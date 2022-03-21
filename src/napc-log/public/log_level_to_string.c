#include <napc-log/_private/_napc-log.h>

const char *napc_logLevelToString(int log_level) {
	switch (log_level) {
		case NAPC_LEVEL_VERBOSE:
			return "verbo";

		case NAPC_LEVEL_TRACE:
			return "trace";

		case NAPC_LEVEL_DEBUG:
			return "debug";

		case NAPC_LEVEL_INFO:
			return "info";

		case NAPC_LEVEL_WARNING:
			return "warn";

		case NAPC_LEVEL_ERROR:
			return "error";

		case NAPC_LEVEL_SECURITY:
			return "secur";
	}

	return "?????";
}
