#if !defined(ARDUINO)
	int PV_napc_linux_argc = 0;// @global
	const char **PV_napc_linux_argv = NULL; // @global

	void libnapc_callBootFunctions(void);
	void napc_main(const char *platform);

	int main(int argc, const char **argv) {
		PV_napc_linux_argc = argc;
		PV_napc_linux_argv = argv;

		libnapc_callBootFunctions();
		napc_main("linux");

		return 0;
	}
#endif
