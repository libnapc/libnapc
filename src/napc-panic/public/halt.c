#include <napc-panic/_private/_napc-panic.h>

static char _message_buffer[256]; // @static

void libnapc_halt(
	const char *file,
	int file_line,
	const char *fn,
	const char *fmt,
	...
) {
	// make sure serial is not muted
	libnapc_unmute();

	libnapc_time time = libnapc_getTimeSinceBoot();

	{
		libnapc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" LIBNAPC_TIME_PRINT_DEC ") Originated by function %s in file %s (line %u)", time, fn, file, file_line
		);

		libnapc_puts(_message_buffer);
	}

	{
		libnapc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" LIBNAPC_TIME_PRINT_DEC ") ", time
		);

		libnapc_puts(_message_buffer);
	}

	{
		va_list args;

		va_start(args, fmt);
		libnapc_vsnprintf(_message_buffer, sizeof(_message_buffer), fmt, args);
		va_end(args);

		libnapc_puts(_message_buffer);
	}

	libnapc_puts("\n\n");

	libnapc_printf(
		"(panic +%010" LIBNAPC_TIME_PRINT_DEC ") The application has experienced a fatal error.\n",
		time
	);

	libnapc_printf(
		"(panic +%010" LIBNAPC_TIME_PRINT_DEC ") There's likely log output above.\n",
		time
	);

	libnapc_printf(
		"(panic +%010" LIBNAPC_TIME_PRINT_DEC ") Application will be terminated.\n",
		time
	);

	// flush serial buffer
	libnapc_puts("\n\n");

	HAL_libnapc_abort();
}
