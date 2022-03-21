#if !defined(ARDUINO)
	#include <napc-rand-source/_private/_napc-rand-source.h>
	#include <stdio.h> // FILE, fopen(), fgetc(), fclose()

	bool HAL_napc_getRandomBit(bool *out, int source) {
		// source is ignored on linux
		NAPC_IGNORE_VALUE(source);

		FILE *fp = fopen("/dev/urandom", "r");

		if (!fp) return false;

		int ch = fgetc(fp);
		fclose(fp);

		if (ch != EOF) {
			*out = !!(ch & 0x01u);

			return true;
		}

		return false;
	}
#endif
