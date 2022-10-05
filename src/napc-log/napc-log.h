#if !defined(NAPC_LOG_h)
	#define NAPC_LOG_h

	#include <libnapc.h>

	void napc_logMessage(
		const char *subsys,
		int level,
		const char *function,
		const char *fmt, ...
	) NAPC_FN_PRINTFLIKE(4, 5);

	typedef void (*napc_logHandlerFunction)(
		void *context,
		const char *subsys,
		int level,
		const char *function,
		const char *message
	);

	/*!
	 * @name napc_addLogHandlerFunction
	 * @brief Add log handler function
	 * @version 2.0.0
	 * @param handler The log handler function
	 * @param context Context to be passed to function
	 * @return
	 * On success a number that can be passed to `napc_removeLogHandlerFunction`.
	 * 
	 * Otherwise a negative number is returned.
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	napc_ssize napc_addLogHandlerFunction(
		napc_logHandlerFunction handler, void *context
	);

	/*!
	 * @name napc_removeLogHandlerFunction
	 * @brief Remove a log handler function
	 * @version 2.0.0
	 * @param log_handler_index Handler index returned by `napc_addLogHandlerFunction`
	 * @changelog 2.0.0 12.04.2022 initial version
	 */
	void napc_removeLogHandlerFunction(
		napc_size log_handler_index
	);

	/*!
	 * @name NAPC_LEVEL_VERBOSE
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `verbose`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_VERBOSE, "This is a verbose log message.");
	 */
	#define NAPC_LEVEL_VERBOSE     0

	/*!
	 * @name NAPC_LEVEL_TRACE
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `trace`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_TRACE, "This is a trace log message.");
	 */
	#define NAPC_LEVEL_TRACE       1

	/*!
	 * @name NAPC_LEVEL_DEBUG
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `debug`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_DEBUG, "This is a debug log message.");
	 */
	#define NAPC_LEVEL_DEBUG       2

	/*!
	 * @name NAPC_LEVEL_INFO
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `info`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_INFO, "This is an info log message.");
	 */
	#define NAPC_LEVEL_INFO        3

	/*!
	 * @name NAPC_LEVEL_WARNING
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `warning`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_WARNING, "This is a warning log message.");
	 */
	#define NAPC_LEVEL_WARNING     4

	/*!
	 * @name NAPC_LEVEL_ERROR
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `error`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_ERROR, "This is an error log message.");
	 */
	#define NAPC_LEVEL_ERROR       5

	/*!
	 * @name NAPC_LEVEL_SECURITY
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Representation of log priority `security`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_SECURITY, "This is a security log message.");
	 */
	#define NAPC_LEVEL_SECURITY    9

	const char *napc_logLevelToString(int log_level) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name NAPC_LOG
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with a specific priority.
	 * @param _cstring_ subsys Subsystem.
	 * @param int level Log level.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG("subsystem", NAPC_LEVEL_INFO, "This is a %s!", "message");
	 */
	#define NAPC_LOG(subsys, level, fmt, ...) \
		napc_logMessage(                      \
			subsys,                           \
			level,                            \
			__func__,                         \
			fmt,                              \
			## __VA_ARGS__                    \
		)

	/*!
	 * @name NAPC_LOG_VERBOSE
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `VERBOSE`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_VERBOSE("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_VERBOSE(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_VERBOSE, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_TRACE
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `TRACE`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_TRACE("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_TRACE(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_TRACE, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_DEBUG
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `DEBUG`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_DEBUG("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_DEBUG(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_DEBUG, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_INFO
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `INFO`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_INFO("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_INFO(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_INFO, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_WARNING
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `WARNING`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_WARNING("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_WARNING(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_WARNING, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_ERROR
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `ERROR`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_ERROR("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_ERROR(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_ERROR, fmt, ## __VA_ARGS__)

	/*!
	 * @name NAPC_LOG_SECURITY
	 * @module Core
	 * @version 1.0.0
	 * @description
	 * Log a message with priority `SECURITY`.
	 * @param _cstring_ subsys Subsystem.
	 * @param _cstring_ fmt printf()-like format string.
	 * @param n/a ... Values to incorporate into string.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * NAPC_LOG_SECURITY("subsystem", "This is a %s!", "message");
	 */
	#define NAPC_LOG_SECURITY(subsys, fmt, ...) \
		NAPC_LOG(subsys, NAPC_LEVEL_SECURITY, fmt, ## __VA_ARGS__)
#endif
