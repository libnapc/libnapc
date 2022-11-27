#if !defined(LIBNAPC_LOG_h)
	#define LIBNAPC_LOG_h

	#include <libnapc-internal.h>

	void libnapc_logMessage(
		const char *subsys,
		int level,
		const char *function,
		const char *fmt, ...
	) LIBNAPC_FN_PRINTFLIKE(4, 5);

	typedef void (*libnapc_logHandlerFunction)(
		void *context,
		const char *subsys,
		int level,
		const char *function,
		const char *message
	);

	/*!
	 * @module Core
	 * @type fn
	 * @fullname libnapc_addLogHandlerFunction
	 * @brief Add log handler function
	 * @version 2.0.0
	 * @param handler The log handler function
	 * @param context Context to be passed to function
	 * @return
	 * On success a number that can be passed to `libnapc_removeLogHandlerFunction`.
	 * 
	 * Otherwise a negative number is returned.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_ssize libnapc_addLogHandlerFunction(
		libnapc_logHandlerFunction handler, void *context
	);

	/*!
	 * @module Core
	 * @type fn
	 * @fullname libnapc_removeLogHandlerFunction
	 * @brief Remove a log handler function
	 * @version 2.0.0
	 * @param log_handler_index Handler index returned by `libnapc_addLogHandlerFunction`
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_removeLogHandlerFunction(
		libnapc_size log_handler_index
	);

	/*!
	 * Representation of log priority `verbose`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_VERBOSE
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_VERBOSE, "This is a verbose log message.");
	 */
	#define LIBNAPC_LEVEL_VERBOSE     0

	/*!
	 * Representation of log priority `trace`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_TRACE
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_TRACE, "This is a trace log message.");
	 */
	#define LIBNAPC_LEVEL_TRACE       1

	/*!
	 * Representation of log priority `debug`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_DEBUG
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_DEBUG, "This is a debug log message.");
	 */
	#define LIBNAPC_LEVEL_DEBUG       2

	/*!
	 * Representation of log priority `info`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_INFO
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_INFO, "This is an info log message.");
	 */
	#define LIBNAPC_LEVEL_INFO        3

	/*!
	 * Representation of log priority `warning`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_WARNING
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_WARNING, "This is a warning log message.");
	 */
	#define LIBNAPC_LEVEL_WARNING     4

	/*!
	 * Representation of log priority `error`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_ERROR
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_ERROR, "This is an error log message.");
	 */
	#define LIBNAPC_LEVEL_ERROR       5

	/*!
	 * Representation of log priority `security`.
	 * 
	 * @module Core
	 * @type macro:var
	 * @fullname LIBNAPC_LEVEL_SECURITY
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_SECURITY, "This is a security log message.");
	 */
	#define LIBNAPC_LEVEL_SECURITY    9

	const char *libnapc_logLevelToString(int log_level) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Log a message with a specific priority.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param level Log level.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG("subsystem", LIBNAPC_LEVEL_INFO, "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG(subsys, level, fmt, ...) \
		libnapc_logMessage(                      \
			subsys,                              \
			level,                               \
			__func__,                            \
			fmt,                                 \
			## __VA_ARGS__                       \
		)

	/*!
	 * Log a message with priority `VERBOSE`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_VERBOSE
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_VERBOSE("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_VERBOSE(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_VERBOSE, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `TRACE`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_TRACE
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_TRACE("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_TRACE(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_TRACE, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `DEBUG`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_DEBUG
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_DEBUG("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_DEBUG(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_DEBUG, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `INFO`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_INFO
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_INFO("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_INFO(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_INFO, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `WARNING`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_WARNING
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_WARNING("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_WARNING(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_WARNING, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `ERROR`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_ERROR
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_ERROR("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_ERROR(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_ERROR, fmt, ## __VA_ARGS__)

	/*!
	 * Log a message with priority `SECURITY`.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_LOG_SECURITY
	 * @version 2.0.0
	 * @param subsys Subsystem.
	 * @param fmt printf()-like format string.
	 * @variadic Values to incorporate into string.
	 * @changelog 2.0.0 initial version
	 * @example
	 * LIBNAPC_LOG_SECURITY("subsystem", "This is a %s!", "message");
	 */
	#define LIBNAPC_LOG_SECURITY(subsys, fmt, ...) \
		LIBNAPC_LOG(subsys, LIBNAPC_LEVEL_SECURITY, fmt, ## __VA_ARGS__)
#endif
