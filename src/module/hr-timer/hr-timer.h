/* <-- add '!' back once ported -->
 * @name HRTimer:intro
 * @brief High-resolution timer
 */
#if !defined(LIBNAPC_MODULE_HRTIMER_h)
	#define LIBNAPC_MODULE_HRTIMER_h

	#include <libnapc-internal.h>
	#include <libnapc-magic/libnapc-magic.h>

	/*!
	 * @module HRTimer
	 * @type type:enum
	 * @fullname libnapc__HRTimerMode
	 * @brief Representation of timer operation mode.
	 * @version 2.0.0
	 * @enum LIBNAPC_HRTIMER_MODE_REGULAR Regular timer mode.
	 * @enum LIBNAPC_HRTIMER_MODE_ONESHOT One-shot timer mode.
	 * @changelog 2.0.0 initial version
	 */
	typedef enum libnapc__HRTimerMode {
		LIBNAPC_HRTIMER_MODE_REGULAR = 0x10, // 0001 0000
		LIBNAPC_HRTIMER_MODE_ONESHOT = 0x20  // 0010 0000
	} libnapc__HRTimerMode;

	/*!
	 * @module HRTimer
	 * @type type:opaque
	 * @fullname libnapc__HRTimer
	 * @brief Representation of a high-resolution timer.
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__HRTimer {
		LIBNAPC_MAGIC_MEMBER; // used to detect uninitialized timers

		libnapc__HRTimerMode mode;

		libnapc_time duration;
		libnapc_time started_at;
		bool expired;
	} libnapc__HRTimer;

	/*!
	 * Initializes a timer with a duration of `duration` microseconds.
	 * 
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_init
	 * @name init
	 * @brief Initialize a high-resolution timer.
	 * @version 2.0.0
	 * @param timer Timer to be initialized.
	 * @param duration Timer duration in microseconds.
	 * @param mode Timer mode.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__HRTimer timer;
	 * 
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * libnapc_HRTimer_init(&timer, 1000, LIBNAPC_HRTIMER_MODE_ONESHOT); // 1000us = 1ms
	 */
	void libnapc_HRTimer_init(libnapc__HRTimer *timer, libnapc_time duration, libnapc__HRTimerMode mode);

	/*!
	 * Creates a timer with a duration of `duration` microseconds.
	 * 
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_create
	 * @name create
	 * @brief Create a high-resolution timer object.
	 * @version 2.0.0
	 * @param duration Timer duration in microseconds.
	 * @param mode Timer mode.
	 * @changelog 2.0.0 initial version
	 * @example
	 * // one-shot mode means _expired will return
	 * // 'true' only ONCE.
	 * libnapc__HRTimer timer = libnapc_HRTimer_create(1000, LIBNAPC_HRTIMER_MODE_ONESHOT); // 1000us = 1ms
	 */
	libnapc__HRTimer libnapc_HRTimer_create(libnapc_time duration, libnapc__HRTimerMode mode);

	/*!
	 * Starts the high-resolution timer `timer`.
	 * 
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_start
	 * @name start
	 * @brief Start a high-resolution timer.
	 * @version 2.0.0
	 * @param timer Timer to start.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__HRTimer timer = libnapc_HRTimer_create(1000, LIBNAPC_HRTIMER_MODE_REGULAR);
	 * 
	 * libnapc_HRTimer_start(&timer);
	 */
	void libnapc_HRTimer_start(libnapc__HRTimer *timer);

	/*!
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_expired
	 * @name expired
	 * @brief Check if a high-resolution timer has expired.
	 * @version 2.0.0
	 * @param timer Timer to check.
	 * @return Returns `true` if timer expired, `false` otherwise.
	 * @note
	 * In REGULAR mode:
	 * 
	 * After the timer expired this function will always return `true`
	 * until timer is restarted with `libnapc_HRTimer_restart`.
	 * @note
	 * In ONESHOT mode:
	 * 
	 * This function will return `true` only once per started timer.
	 * Subsequent calls on the same timer will return `false`.
	 * @changelog 2.0.0 initial version
	 */
	bool libnapc_HRTimer_expired(libnapc__HRTimer *timer) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_getMode
	 * @name getMode
	 * @brief Return the timer mode.
	 * @version 2.0.0
	 * @param timer Timer to return mode of.
	 * @return Returns the set timer mode.
	 * @changelog 2.0.0 initial version
	 */
	libnapc__HRTimerMode libnapc_HRTimer_getMode(const libnapc__HRTimer *timer) LIBNAPC_FN_WARN_UNUSED_RET();

	/*!
	 * @module HRTimer
	 * @type fn
	 * @fullname libnapc_HRTimer_restart
	 * @name restart
	 * @brief Restart a timer.
	 * @version 2.0.0
	 * @param timer Timer to be restarted.
	 * @changelog 2.0.0 initial version
	 * @example
	 * if (libnapc_HRTimer_expired(&timer)) {
	 *     libnapc_HRTimer_restart(&timer);
	 * }
	 */
	void libnapc_HRTimer_restart(libnapc__HRTimer *timer);
#endif
