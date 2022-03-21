#if defined(ARDUINO)
	extern "C" {
		void libnapc_callBootFunctions(void);
		void napc_main(const char *platform);

		void setup() {
			libnapc_callBootFunctions();
			napc_main("arduino");
		}

		void loop() {}
	}
#endif
