#if !defined(LIBNAPC_DELAY_h)
	#define LIBNAPC_DELAY_h

	#include <libnapc-internal.h>

	/*!
	 * Delay program execution.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_delay
	 * @brief Delay program execution.
	 * @version 2.0.0
	 * @warning
	 * This function will block execution for a set amount of time.
	 * 
	 * It's better to use non-blocking code, see `napc__Timer` and `napc__HRTimer`.
	 * @param amount The amount in milliseconds.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delay(1000); // wait for 1 second
	 * 
	 * napc_printf("World!");
	 */
	void libnapc_delay(libnapc_time amount);

	/*!
	 * Delay program execution.
	 * 
	 * @module Core
	 * @type fn
	 * @fullname libnapc_delayUs
	 * @brief Delay program execution.
	 * @version 2.0.0
	 * @warning
	 * This function will block execution for a set amount of time.
	 * 
	 * It's better to use non-blocking code, see `napc__Timer` and `napc__HRTimer`.
	 * @param amount The amount in microseconds.
	 * @changelog 2.0.0 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delayUs(250000); // wait for 250 milliseconds
	 * 
	 * napc_printf("World!");
	 */
	void libnapc_delayUs(libnapc_time amount);
#endif
