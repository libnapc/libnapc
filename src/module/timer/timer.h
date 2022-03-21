#if !defined(NAPC_MODULE_TIMER_h)
	#define NAPC_MODULE_TIMER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Timer
	 * @brief Representation of a timer.
	 * @version 1.0.0
	 * @notes
	 * Treat this type as opaque.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		NAPC_MAGIC_MEMBER; // used to detect uninitialized timers

		napc_time duration;
		napc_time started_at;
		bool expired;
	} napc__Timer;

	/*!
	 * @name napc_Timer_init
	 * @brief Initialize a timer.
	 * @version 1.0.0
	 * @description
	 * Initializes a timer with a duration of `duration` milliseconds.
	 * @param timer Pointer to `napc__Timer` to be initialized.
	 * @param duration Timer duration in milliseconds.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Timer timer;
	 * 
	 * napc_Timer_init(&timer, 1000); // 1000ms = 1s
	 */
	void napc_Timer_init(napc__Timer *timer, napc_time duration);

	/*!
	 * @name napc_Timer_create
	 * @brief Create a timer object.
	 * @version 1.0.0
	 * @description
	 * Creates a timer with a duration of `duration` milliseconds.
	 * @param duration Timer duration in milliseconds.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Timer timer = napc_Timer_create(1000); // 1000ms = 1s
	 */
	napc__Timer napc_Timer_create(napc_time duration);

	/*!
	 * @name napc_Timer_start
	 * @brief Start a timer.
	 * @version 1.0.0
	 * @description
	 * Starts the timer `timer`.
	 * @param timer Pointer to `napc__Timer` variable.
	 * @notes
	 * This function will return `true` only once per started timer.
	 * Subsequent calls on the same timer will return `false`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__Timer timer = napc_Timer_create(1000);
	 * 
	 * napc_Timer_start(&timer);
	 */
	void napc_Timer_start(napc__Timer *timer);

	/*!
	 * @name napc_Timer_expired
	 * @brief Check if a timer has expired.
	 * @version 1.0.0
	 * @param timer Pointer to `napc__Timer` variable.
	 * @return Returns `true` if timer expired, `false` otherwise.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	bool napc_Timer_expired(napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Timer_restart
	 * @brief Restart a timer.
	 * @version 1.0.0
	 * @param timer Pointer to napc__Timer variable.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * if (napc_Timer_expired(&timer)) {
	 *     napc_Timer_restart(&timer);
	 * }
	 */
	void napc_Timer_restart(napc__Timer *timer);
#endif
