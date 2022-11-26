#if !defined(LIBNAPC_CORE_h)
	#define LIBNAPC_CORE_h

	#include <libnapc-internal.h>

	#include <napc-panic/napc-panic.h>

	/*!
	 * Represents an action to be taken after an access to a resource (buffer) failed.
	 * 
	 * @module Core
	 * @type type:enum
	 * @fullname libnapc__AccessFailureMode
	 * @brief Action to be taken on an access failure.
	 * @version 2.0.0
	 * @enum LIBNAPC_ACCESS_FAILURE_MODE_NONE Do nothing.
	 * @enum LIBNAPC_ACCESS_FAILURE_MODE_LOG Emit a log message of type 'error'. This is the default.
	 * @enum LIBNAPC_ACCESS_FAILURE_MODE_PANIC Call LIBNAPC_PANIC.
	 * @changelog 2.0.0 initial version
	 * @note
	 * Failure mode `PANIC` should be used when you're absolutely sure access to a resource will not fail.
	 * 
	 * Failure mode `NONE` can be used to disable logging.
	 * 
	 * Failure mode `LOG` is the default behaviour.
	 */
	typedef enum libnapc__AccessFailureMode {
		LIBNAPC_ACCESS_FAILURE_MODE_NONE  = 1,
		LIBNAPC_ACCESS_FAILURE_MODE_LOG   = 2,
		LIBNAPC_ACCESS_FAILURE_MODE_PANIC = 3
	} libnapc__AccessFailureMode;

	/*!
	 * Sets the default access failure modes for modules like
	 * `Writer`, `Reader` etc.
	 * 
	 * The default is `LIBNAPC_ACCESS_FAILURE_MODE_LOG`: emit a log message of type 'error'.
	 * 
	 * Setting a new default mode can be useful for debugging, as shown in the example.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_setDefaultAccessFailureMode
	 * @brief Set default failure access mode.
	 * @version 2.0.0
	 * @param new_default_mode The new default mode to be used.
	 * @return Returns the previous set default access failure mode.
	 * @changelog 2.0.0 initial version
	 * @example
	 * void napc_app_setup(const char *platform) {
	 *     // crash program on an access failure
	 *     #if defined(DEBUG)
	 *         libnapc_setDefaultAccessFailureMode(LIBNAPC_ACCESS_FAILURE_MODE_PANIC);
	 *     #endif
	 *     // init
	 *     // ...
	 * }
	 */
	libnapc__AccessFailureMode libnapc_setDefaultAccessFailureMode(
		libnapc__AccessFailureMode new_default_mode
	);

	// used by internal API -> Writer, Reader etc.
	libnapc__AccessFailureMode PV_napc_getDefaultAccessFailureMode(void);
	// used by internal API -> Writer, Reader etc.
	bool PV_napc_validateAccessFailureMode(libnapc__AccessFailureMode mode);

	/*!
	 * @module Core
	 * @type fn
	 * @fullname libnapc_getFreeMemory
	 * @brief Get available memory.
	 * @version 2.0.0
	 * @return
	 * Returns the number of free bytes (on the stack) available.
	 * @changelog 2.0.0 initial version
	 */
	libnapc_size libnapc_getFreeMemory(void) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * Make an assertion.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_ASSERT
	 * @brief Make an assertion.
	 * @version 2.0.0
	 * @param expr Expression to assert.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc_u8 var = 13;
	 * 
	 * LIBNAPC_ASSERT(var == 13);
	 */
	#define LIBNAPC_ASSERT(expr)                    \
		do {                                        \
			if (!(expr)) {                          \
				LIBNAPC_PANIC("Assertion failed."); \
			}                                       \
		} while(false)
#endif
