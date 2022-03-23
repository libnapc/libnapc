<?php

class XPHPUtils_shell_Program {
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

return function($command, $args) {
	return new XPHPUtils_shell_Program($command, $args);
};
