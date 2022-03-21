<?php

require_once __DIR__."/../php.lib/exec_or_die.php";

class Program {
	private $_proc;
	private $_was_running = true;
	private $_exit_code = -1;

	public function __construct($command, $args = []) {
		$real_command = $command." ";

		foreach ($args as $arg) {
			$real_command .= escapeshellarg($arg)." ";
		}

		//fwrite(STDERR, "Executing '$real_command'\n");

		// todo: catch output
		$this->_proc = proc_open(
			$real_command, [
				STDIN, STDOUT, STDOUT
			], $pipes
		);
	}

	public function getExitCode() {
		$status = proc_get_status($this->_proc);

		if ($status["running"] !== $this->_was_running) {
			$this->_exit_code = $status["exitcode"];
		}

		$this->_was_running = $status["running"];

		return $status["running"] ? -1 : $this->_exit_code;
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

	array_push($lines, "dist/tmp_files/napc_version.c");

	foreach ($lines as $line) {
		$line = trim($line);

		if (!strlen($line)) continue;

		$file_path = realpath(__DIR__."/../$line");
		$object_file = "tmp/".str_replace("/", "_", $file_path).".o";

		$proc = new Program($cc, [
			"-Wall", "-Wextra", "-Wpedantic", "-I./src/",
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
				if ($proc->getExitCode() !== 0) {
					fwrite(STDERR, "Compilation failed\n");
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

create_static_lib("gcc", "libnapc.a");
create_static_lib("aarch64-linux-gnu-gcc", "libnapc-aarch64.a");
