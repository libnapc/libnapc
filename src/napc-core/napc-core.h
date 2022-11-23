#if !defined(NAPC_CORE_h)
	#define NAPC_CORE_h

	#include <libnapc.h>

	#include <napc-panic/napc-panic.h>

	extern void napc_setup(const char *platform);
	extern bool napc_loop(napc_time uptime);

	/*!
	 * @name napc__AccessFailureMode
	 * @brief Action to be taken on an access failure.
	 * @module Core
	 * @version 2.0.0
	 * @description
	 * Represents an action to be taken after an access to a resource (buffer) failed.
	 * @enum NAPC_ACCESS_FAILURE_MODE_NONE Do nothing.
	 * @enum NAPC_ACCESS_FAILURE_MODE_LOG Emit a log message of type 'error'. This is the default.
	 * @enum NAPC_ACCESS_FAILURE_MODE_PANIC Call NAPC_PANIC.
	 * @changelog 2.0.0 10.02.2022 initial version
	 * @notes
	 * Failure mode `PANIC` should be used when you're absolutely sure access to a resource will not fail.
	 * 
	 * Failure mode `NONE` can be used to disable logging.
	 * 
	 * Failure mode `LOG` is the default behaviour.
	 */
	typedef enum napc__AccessFailureMode {
		NAPC_ACCESS_FAILURE_MODE_NONE  = 1,
		NAPC_ACCESS_FAILURE_MODE_LOG   = 2,
		NAPC_ACCESS_FAILURE_MODE_PANIC = 3
	} napc__AccessFailureMode;

	/*!
	 * @name napc_setDefaultAccessFailureMode
	 * @brief Set default failure access mode.
	 * @version 2.0.0
	 * @description
	 * Sets the default access failure modes for modules like
	 * `Writer`, `Reader` etc.
	 * 
	 * The default is `NAPC_ACCESS_FAILURE_MODE_LOG`: emit a log message of type 'error'.
	 * 
	 * Setting a new default mode can be useful for debugging, as shown in the example.
	 * 
	 * @param new_default_mode The new default mode to be used.
	 * @return Returns the previous set default access failure mode.
	 * @changelog 2.0.0 10.02.2022 initial version
	 * @example
	 * void napc_app_setup(const char *platform) {
	 *     // crash program on an access failure
	 *     #if defined(DEBUG)
	 *         napc_setDefaultAccessFailureMode(NAPC_ACCESS_FAILURE_MODE_PANIC);
	 *     #endif
	 *     // init
	 *     // ...
	 * }
	 */
	napc__AccessFailureMode napc_setDefaultAccessFailureMode(
		napc__AccessFailureMode new_default_mode
	);

	// used by internal API -> Writer, Reader etc.
	napc__AccessFailureMode PV_napc_getDefaultAccessFailureMode(void);
	// used by internal API -> Writer, Reader etc.
	bool PV_napc_validateAccessFailureMode(napc__AccessFailureMode mode);

	/*!
	 * @name napc_getFreeMemory
	 * @brief Get available memory.
	 * @version 1.0.0
	 * @return
	 * Returns the number of free bytes (on the stack) available.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	napc_size napc_getFreeMemory(void) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name NAPC_ASSERT
	 * @module Core
	 * @brief Make an assertion.
	 * @version 1.0.0
	 * @description
	 * Assert an expression.
	 * @param bool expr Expression to assert.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_u8 var = 13;
	 * 
	 * NAPC_ASSERT(var == 13);
	 */
	#define NAPC_ASSERT(expr)                    \
		do {                                     \
			if (!(expr)) {                       \
				NAPC_PANIC("Assertion failed."); \
			}                                    \
		} while(false)
#endif
