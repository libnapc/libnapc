#if !defined(NAPC_MODULE_TIMER_h)
	#define NAPC_MODULE_TIMER_h

	#include <libnapc-internal.h>
	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__TimerMode
	 * @module Timer
	 * @brief Representation of timer operation mode.
	 * @version 2.0.0
	 * @enum NAPC_TIMER_MODE_REGULAR Regular timer mode.
	 * @enum NAPC_TIMER_MODE_ONESHOT One-shot timer mode.
	 * @changelog 2.0.0 21.10.2022 initial version
	 */
	typedef enum napc__TimerMode {
		NAPC_TIMER_MODE_REGULAR = 0x01, // 0000 0001
		NAPC_TIMER_MODE_ONESHOT = 0x02  // 0000 0010
	} napc__TimerMode;

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

		napc__TimerMode mode;

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
	 * @param mode Timer mode.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * napc__Timer timer;
	 * 
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * napc_Timer_init(&timer, 1000, NAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
	 */
	void napc_Timer_init(napc__Timer *timer, napc_time duration, napc__TimerMode mode);

	/*!
	 * @name napc_Timer_create
	 * @brief Create a timer object.
	 * @version 2.0.0
	 * @description
	 * Creates a timer with a duration of `duration` milliseconds.
	 * @param duration Timer duration in milliseconds.
	 * @param mode Timer mode.
	 * @changelog 2.0.0 21.10.2022 initial version
	 * @example
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * napc__Timer timer = napc_Timer_create(1000, NAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
	 */
	napc__Timer napc_Timer_create(napc_time duration, napc__TimerMode mode);

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
	 * In REGULAR mode:
	 * 
	 * After the timer expired this function will always return `true`
	 * until timer is restarted with `napc_Timer_restart`.
	 * @notes
	 * In ONESHOT mode:
	 * 
	 * This function will return `true` only once per started timer.
	 * Subsequent calls on the same timer will return `false`.
	 * @changelog 2.0.0 25.03.2022 initial version
	 */
	bool napc_Timer_expired(napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();

	/*!
	 * @name napc_Timer_getMode
	 * @brief Return the timer mode.
	 * @version 2.0.0
	 * @param timer Timer to return mode of.
	 * @return Returns the set timer mode.
	 * @changelog 2.0.0 25.03.2022 initial version
	 */
	napc__TimerMode napc_Timer_getMode(const napc__Timer *timer) NAPC_FN_WARNUNUSED_RET();

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
