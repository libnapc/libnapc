#include <napc-log/_private/_napc-log.h>

const char *libnapc_logLevelToString(int log_level) {
	switch (log_level) {
		case LIBNAPC_LEVEL_VERBOSE:
			return "verbo";

		case LIBNAPC_LEVEL_TRACE:
			return "trace";

		case LIBNAPC_LEVEL_DEBUG:
			return "debug";

		case LIBNAPC_LEVEL_INFO:
			return "info";

		case LIBNAPC_LEVEL_WARNING:
			return "warn";

		case LIBNAPC_LEVEL_ERROR:
			return "error";

		case LIBNAPC_LEVEL_SECURITY:
			return "secur";
	}

	return "?????";
}
