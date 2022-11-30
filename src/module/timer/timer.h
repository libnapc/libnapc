#if !defined(LIBNAPC_MODULE_TIMER_h)
	#define LIBNAPC_MODULE_TIMER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>

	/*!
	 * @module Timer
	 * @type type:enum
	 * @fullname libnapc__TimerMode
	 * @brief Representation of timer operation mode.
	 * @version 2.0.0
	 * @enum LIBNAPC_TIMER_MODE_REGULAR Regular timer mode.
	 * @enum LIBNAPC_TIMER_MODE_ONESHOT One-shot timer mode.
	 * @changelog 2.0.0 initial version
	 */
	typedef enum libnapc__TimerMode {
		LIBNAPC_TIMER_MODE_REGULAR = 0x01, // 0000 0001
		LIBNAPC_TIMER_MODE_ONESHOT = 0x02  // 0000 0010
	} libnapc__TimerMode;

	/*!
	 * @module Timer
	 * @type type:opaque
	 * @fullname libnapc__Timer
	 * @brief Representation of a timer.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__Timer {
		LIBNAPC_MAGIC_MEMBER_DEFINITION

		libnapc__TimerMode mode;

		libnapc_time duration;
		libnapc_time started_at;
		bool expired;
	} libnapc__Timer;

	/*!
	 * Initializes a timer with a duration of `duration` milliseconds.
	 * 
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_init
	 * @name init
	 * @brief Initialize a timer.
	 * @version 2.0.0
	 * @param timer Timer to be initialized.
	 * @param duration Timer duration in milliseconds.
	 * @param mode Timer mode.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Timer timer;
	 * 
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * libnapc_Timer_init(&timer, 1000, LIBNAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
	 */
	void libnapc_Timer_init(libnapc__Timer *timer, libnapc_time duration, libnapc__TimerMode mode);

	/*!
	 * Creates a timer with a duration of `duration` milliseconds.
	 * 
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_create
	 * @name create
	 * @brief Create a timer object.
	 * @version 2.0.0
	 * @param duration Timer duration in milliseconds.
	 * @param mode Timer mode.
	 * @changelog 2.0.0 initial version
	 * @example
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * libnapc__Timer timer = libnapc_Timer_create(1000, LIBNAPC_TIMER_MODE_ONESHOT); // 1000ms = 1s
	 */
	libnapc__Timer libnapc_Timer_create(libnapc_time duration, libnapc__TimerMode mode);

	/*!
	 * Starts the timer `timer`.
	 * 
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_start
	 * @name start
	 * @brief Start a timer.
	 * @version 2.0.0
	 * @param timer Timer to start.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__Timer timer = libnapc_Timer_create(1000);
	 * 
	 * libnapc_Timer_start(&timer);
	 */
	void libnapc_Timer_start(libnapc__Timer *timer);

	/*!
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_expired
	 * @name expired
	 * @brief Check if a timer has expired.
	 * @version 2.0.0
	 * @param timer Timer to check.
	 * @return Returns `true` if timer expired, `false` otherwise.
	 * @note
	 * In REGULAR mode:
	 * 
	 * After the timer expired this function will always return `true`
	 * until timer is restarted with `napc_Timer_restart`.
	 * @note
	 * In ONESHOT mode:
	 * 
	 * This function will return `true` only once per started timer.
	 * Subsequent calls on the same timer will return `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_Timer_expired(libnapc__Timer *timer) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_getMode
	 * @name getMode
	 * @brief Return the timer mode.
	 * @version 2.0.0
	 * @param timer Timer to return mode of.
	 * @return Returns the set timer mode.
	 * @changelog 2.0.0 initial version
	 */
	libnapc__TimerMode libnapc_Timer_getMode(const libnapc__Timer *timer) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @module Timer
	 * @type fn
	 * @fullname libnapc_Timer_restart
	 * @name restart
	 * @brief Restart a timer.
	 * @version 2.0.0
	 * @param timer Timer to be restarted.
	 * @changelog 2.0.0 initial version
	 * @example
	 * if (libnapc_Timer_expired(&timer)) {
	 *     libnapc_Timer_restart(&timer);
	 * }
	 */
	void libnapc_Timer_restart(libnapc__Timer *timer);
#endif
