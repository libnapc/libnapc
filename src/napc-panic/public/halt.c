#include <napc-panic/_private/_napc-panic.h>

static char _message_buffer[256]; // @static

void napc_halt(
	const char *file,
	int file_line,
	const char *fn,
	const char *fmt,
	...
) {
	// make sure serial is not muted
	napc_unmute();

	napc_time time = napc_getTimeSinceBoot();

	{
		napc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" NAPC_TIME_PRINTF ") Originated by function %s in file %s (line %u)", time, fn, file, file_line
		);

		libnapc_puts(_message_buffer);
	}

	{
		napc_snprintf(
			_message_buffer, sizeof(_message_buffer),
			"\n\n(panic +%010" NAPC_TIME_PRINTF ") ", time
		);

		libnapc_puts(_message_buffer);
	}

	{
		va_list args;

		va_start(args, fmt);
		napc_vsnprintf(_message_buffer, sizeof(_message_buffer), fmt, args);
		va_end(args);

		libnapc_puts(_message_buffer);
	}

	libnapc_puts("\n\n");

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") The application has experienced a fatal error.\n",
		time
	);

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") There's likely log output above.\n",
		time
	);

	napc_printf(
		"(panic +%010" NAPC_TIME_PRINTF ") Application will be terminated.\n",
		time
	);

	// flush serial buffer
	libnapc_puts("\n\n");

	HAL_napc_abort();
}
