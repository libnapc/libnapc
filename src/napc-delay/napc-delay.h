#if !defined(NAPC_DELAY_h)
	#define NAPC_DELAY_h

	#include <libnapc.h>

	/*!
	 * @name napc_delay
	 * @brief Delay program execution.
	 * @version 1.0.0
	 * @description Delay program execution.
	 * @warning
	 * This function will block execution for a set amount of time.
	 * 
	 * It's better to use non-blocking code, see `napc__Timer` and `napc__OSTimer`.
	 * @param amount The amount in milliseconds.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delay(1000); // wait for 1 second
	 * 
	 * napc_printf("World!");
	 */
	void napc_delay(napc_time amount);

	/*!
	 * @name napc_delayUs
	 * @brief Delay program execution.
	 * @version 1.0.0
	 * @description Delay program execution.
	 * @warning
	 * This function will block execution for a set amount of time.
	 * 
	 * It's better to use non-blocking code, see `napc__Timer` and `napc__OSTimer`.
	 * @param amount The amount in microseconds.
	 * @flags hw
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc_printf("Hello ");
	 * 
	 * napc_delayUs(250000); // wait for 250 milliseconds
	 * 
	 * napc_printf("World!");
	 */
	void napc_delayUs(napc_time amount);
#endif
