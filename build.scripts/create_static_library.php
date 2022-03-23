<?php

require_once __DIR__."/../php.lib/exec_or_die.php";

class Program {
	private $_proc;
	private $_was_running = true;
	private $_exit_code = -1;
	private $_pipes = [];
	private $_stdout = "";
	private $_stderr = "";
	private $_cmd = "";

	public function __construct($command, $args = []) {
		$real_command = $command." ";

		foreach ($args as $arg) {
			$real_command .= escapeshellarg($arg)." ";
		}

		$this->_cmd = $real_command;

		$this->_proc = proc_open(
			$real_command, [
				STDIN, ["pipe", "w"], ["pipe", "w"]
			], $this->_pipes
		);
	}

	public function getCommand() {
		return $this->_cmd;
	}

	public function getExitCode() {
		$status = proc_get_status($this->_proc);

		if ($status["running"] !== $this->_was_running) {
			$this->_exit_code = $status["exitcode"];

			$this->_stdout = stream_get_contents($this->_pipes[1]);
			$this->_stderr = stream_get_contents($this->_pipes[2]);

			fclose($this->_pipes[1]);
			fclose($this->_pipes[2]);
		}

		$this->_was_running = $status["running"];

		return $status["running"] ? -1 : $this->_exit_code;
	}

	public function getOutput() {
		return [
			"stdout" => $this->_stdout,
			"stderr" => $this->_stderr
		];
	}
}

function create_static_lib($cc, $output_name) {
	chdir(__DIR__."/../");

	exec_or_die("rm -rf tmp");
	exec_or_die("mkdir tmp");

	$output = shell_exec(
		"find src -name '*.c' && find __tests__/_processed  __tests__/__tests__.c -name '*.c'"
	);

	$lines = explode("\n", $output);
	$object_files = [];
	$procs = [];

	$git = (require (__DIR__."/../_git.php"))();

	$git_branch = $git["branch"];
	$git_head = $git["HEAD"];
	$release_version = $git["release_version"];

	array_push($lines, "dist/tmp_files/napc_version.c");

	foreach ($lines as $line) {
		$line = trim($line);

		if (!strlen($line)) continue;

		$file_path = realpath(__DIR__."/../$line");
		$object_file = "tmp/".str_replace("/", "_", $file_path).".o";

		$proc = new Program($cc, [
			"-Wall", "-Wextra", "-Wpedantic", "-I./src/",
			"-DLIBNAPC_GIT_BRANCH=\"$git_branch\"",
			"-DLIBNAPC_GIT_HEAD=\"$git_head\"",
			"-DLIBNAPC_RELEASE_VERSION=\"$release_version\"",
			$file_path, "-c", "-o", $object_file
		]);

		fwrite(STDERR, "Processing $line\n");

		$procs[] = $proc;
	}

	fwrite(STDERR, "Waiting for compilation to be done ... \n");

	while (true) {
		$n_procs_done = 0;

		foreach ($procs as $proc) {
			if ($proc->getExitCode() !== -1) {
				$exit_code = $proc->getExitCode();

				fwrite(STDERR, $proc->getCommand()."\n");

				if ($exit_code !== 0) {
					fwrite(STDERR, "\033[0;31m");
				} else {
					fwrite(STDERR, "\033[1;30m");
				}

				foreach ($proc->getOutput() as $stream => $output) {
					$lines = explode("\n", $output);

					foreach ($lines as $line) {
						fwrite(STDERR, "$stream: $line\n");
					}
				}

				fwrite(STDERR, "\033[0;0m");

				if ($exit_code !== 0) {
					exit(1);
				}

				$n_procs_done++;
			}
		}

		if ($n_procs_done === sizeof($procs)) break;
	}

	exec_or_die("ar rcs dist/$output_name tmp/*.o");
	exec_or_die("rm -rf tmp");
}

create_static_lib("x86_64-linux-gnu-gcc", "libnapc-x86_64.a");
create_static_lib("aarch64-linux-gnu-gcc", "libnapc-aarch64.a");
