#if !defined(ARDUINO)
	void libnapc_callBootFunctions(void);
	void napc_main(const char *platform);

	int main(void) {
		libnapc_callBootFunctions();
		napc_main("linux");

		return 0;
	}
#endif
