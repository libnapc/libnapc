#include <napc-log/_private/_napc-log.h>

static char _message_buffer[256]; // @static
static char _fn[64]; // @static

static void _shortenFunctionName(const char *fn, char *buf) {
	libnapc_size fn_len = libnapc_strlen(fn);
	const libnapc_size max = 40;

	if (max >= fn_len) {
		libnapc_strncpy(buf, fn, 64);
		return;
	}

	libnapc_size start = fn_len - (max - 1);

	for (libnapc_size i = 0; i < max; ++i) {
		buf[i] = fn[start + i];
	}

	buf[0] = '.';
	buf[1] = '.';
	buf[2] = '.';

	buf[max - 1] = 0;
}

static void _callLogHandlers(
	const char *subsys,
	int level,
	const char *function,
	const char *message
) {
	// call log handler
	for (libnapc_size i = 0; i < LIBNAPC_ARRAY_ELEMENTS(PV_libnapc_log_handler_array); ++i) {
		libnapc_logHandlerFunction handler = PV_libnapc_log_handler_array[i];
		void *handler_context = PV_libnapc_log_handler_context_array[i];

		if (handler) {
			handler(
				handler_context,
				subsys,
				level,
				function,
				message
			);
		}
	}
}

void libnapc_logMessage(
	const char *subsys,
	int level,
	const char *function,
	const char *fmt, ...
) {
	libnapc_time time = libnapc_getTimeSinceBoot();

	if (PV_libnapc_log_colorful_output) {
		if (level == LIBNAPC_LEVEL_INFO) {
			libnapc_puts("\033[0;34m");
		} else if (level == LIBNAPC_LEVEL_WARNING) {
			libnapc_puts("\033[0;33m");
		} else if (level == LIBNAPC_LEVEL_ERROR) {
			libnapc_puts("\033[0;31m");
		}
	}

	{
		const char *label = libnapc_logLevelToString(level);

		libnapc_mzero(_fn, sizeof(_fn));
		_shortenFunctionName(function, _fn);

		libnapc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"(%-5s +%010" LIBNAPC_TIME_PRINT_DEC " / %8" LIBNAPC_SIZE_PRINT_DEC ") subsys=%-23s [%40s] ",
			label, time, libnapc_getFreeMemory(), subsys, _fn
		);

		libnapc_puts(_message_buffer);
	}

	{
		va_list args;

		va_start(args, fmt);
		libnapc_vsnprintf(_message_buffer, sizeof(_message_buffer), fmt, args);
		va_end(args);
	}

	_callLogHandlers(
		subsys, level, function, _message_buffer
	);

	for (libnapc_size i = 0; i < libnapc_strlen(_message_buffer); ++i) {
		const char ch = _message_buffer[i];

		libnapc_putc(ch);

		if (ch == '\n') {
			for (libnapc_size i = 0; i < 105; ++i) {
				libnapc_putc(' ');
			}
		}
	}

	if (PV_libnapc_log_colorful_output) {
		libnapc_puts("\033[0;0m");
	}

	libnapc_puts("\n");
}
