#if !defined(NAPC_MODULE_TIMER_h)
	#define NAPC_MODULE_TIMER_h

	#include <libnapc.h>
	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__Timer
	 * @module Timer
	 * @brief Representation of a timer.
	 * @version 2.0.0
	 * @opaque
	 * @changelog 2.0.0 25.03.2022 initial version
	 */
	typedef struct napc__Timer {
		NAPC_MAGIC_MEMBER; // used to detect uninitialized timers

		napc_time duration;
		napc_time started_at;
		bool expired;
	} napc__Timer;

	/*!
	 * @name napc_Timer_init
	 * @brief Initialize a timer.
	 * @version 2.0.0
	 * @description
	 * Initializes a timer with a duration of `duration` milliseconds.
	 * @param timer Timer to be initialized.
	 * @param duration Timer duration in milliseconds.
	 * @changelog 2.0.0 25.03.2022 initial version
	 * @example
	 * napc__Timer timer;
	 * 
	 * napc_Timer_init(&timer, 1000); // 1000ms = 1s
	 */
	void napc_Timer_init(napc__Timer *timer, napc_time duration);

	/*!
	 * @name napc_Timer_create
	 * @brief Create a timer object.
	 * @version 2.0.0
	 * @description
	 * Creates a timer with a duration of `duration` milliseconds.
	 * @param duration Timer duration in milliseconds.
	 * @changelog 2.0.0 25.03.2022 initial version
	 * @example
	 * napc__Timer timer = napc_Timer_create(1000); // 1000ms = 1s
	 */
	napc__Timer napc_Timer_create(napc_time duration);

	/*!
	 * @name napc_Timer_start
	 * @brief Start a timer.
	 * @version 2.0.0
	 * @description
	 * Starts the timer `timer`.
	 * @param timer Timer to start.
	 * @changelog 2.0.0 25.03.2022 initial version
	 * @example
	 * napc__Timer timer = napc_Timer_create(1000);
	 * 
	 * napc_Timer_start(&timer);
	 */
	void napc_Timer_start(napc__Timer *timer);

	/*!
	 * @name napc_Timer_expired
	 * @brief Check if a timer has expired.
	 * @version 2.0.0
	 * @param timer Timer to check.
	 * @return Returns `true` if timer expired, `false` otherwise.
	 * @notes
	 * After the timer expired this function will always return `true`
	 * until timer is restarted with `napc_Timer_restart`.
	 * @changelog 2.0.0 25.03.2022 initial version
	 */
	bool napc_Timer_expired(napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Timer_restart
	 * @brief Restart a timer.
	 * @version 2.0.0
	 * @param timer Timer to be restarted.
	 * @changelog 2.0.0 25.03.2022 initial version
	 * @example
	 * if (napc_Timer_expired(&timer)) {
	 *     napc_Timer_restart(&timer);
	 * }
	 */
	void napc_Timer_restart(napc__Timer *timer);
#endif
