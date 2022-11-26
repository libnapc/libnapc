/**
 * This file contains macros hiding away compiler specific instructions.
 */
#if !defined(LIBNAPC_COMPILER_h)
	#define LIBNAPC_COMPILER_h

	// Source: https://stackoverflow.com/a/39618857/2005038
	/* Normally casting an expression to void discards its value, but GCC
	   versions 3.4 and newer have __attribute__ ((__warn_unused_result__))
	   which may cause unwanted diagnostics in that case.  Use __typeof__
	   and __extension__ to work around the problem, if the workaround is
	   known to be needed.  */
	#if 3 < __GNUC__ + (4 <= __GNUC_MINOR__)
		#define LIBNAPC_IGNORE_VALUE(x) \
			(__extension__ ({ __typeof__ (x) __x = (x); (void) __x; }))
	#else
		#define LIBNAPC_IGNORE_VALUE(x) ((void) (x))
	#endif

	#define LIBNAPC_FN_PRINTFLIKE(_1, _2) __attribute__((format(printf, _1, _2)))

	/*!
	 * Tell the compiler to emit a warning if the return value of a function is not used.
	 * 
	 * @module Core
	 * @type macro:fn
	 * @fullname LIBNAPC_FN_WARN_UNUSED_RET
	 * @version 2.0.0
	 * @changelog 2.0.0 initial version
	 * @example
	 * int my_function() LIBNAPC_FN_WARN_UNUSED_RET() {
	 *     return 4;
	 * }
	 * 
	 * int main(void) {
	 *     my_function(); // will generate a compiler warning
	 * 
	 *     return 0;
	 * }
	 */
	#define LIBNAPC_FN_WARN_UNUSED_RET()  __attribute__((warn_unused_result))
	#define LIBNAPC_FN_NORETURN()         __attribute__((noreturn))

	#define LIBNAPC_DEPRECATED()          __attribute__((deprecated))

	// give compiler a hint that `expr` is likely to evaluate to 'false'
	#define LIBNAPC_UNLIKELY(expr) __builtin_expect(!!(expr), 0)

	// give compiler a hint that `expr` is likely to evaluate to 'true'
	#define LIBNAPC_LIKELY(expr) __builtin_expect(!!(expr), 1)
#endif
