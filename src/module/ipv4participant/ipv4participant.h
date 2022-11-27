/*!
 * @name IPv4Participant:intro
 * @description
 * To reduce parameter count this module is used to combine an IPv4-Address and a port number:
 * 
 * ```c
 * // Holds address for google's DNS server 8.8.8.8:53
 * napc__IPv4Participant google_dns;
 * 
 * // Initialize google_dns variable
 * napc_IPv4Participant_init(&google_dns, "8.8.8.8", 53);
 * ```
 */
#if !defined(LIBNAPC_MODULE_IPV4PARTICIPANT_h)
	#define LIBNAPC_MODULE_IPV4PARTICIPANT_h

	#include <libnapc-internal.h>

	#include <libnapc-magic/libnapc-magic.h>

	/*!
	 * @name napc__IPv4Participant
	 * @module IPv4Participant
	 * @brief Representation a network device.
	 * @version 1.0.0
	 * @description
	 * Representation of a participant in the internet protocol version 4 (IPv4).
	 * @field addr IPv4-Address as string in format `a.b.c.d`.
	 * @field port Port number.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct libnapc__IPv4Participant {
		LIBNAPC_MAGIC_MEMBER;

		char addr[32];
		libnapc_u16 port;
	} libnapc__IPv4Participant;

	/*!
	 * @name napc_IPv4Participant_init
	 * @brief Initialize a participant.
	 * @version 1.0.0
	 * @description
	 * Initialize a participant.
	 * @param participant Pointer to instance to initialize.
	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
	 * @param port Port of participant.
	 * @notes
	 * Input address (`addr`) will be copied into `participant`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void libnapc_IPv4Participant_init(
		libnapc__IPv4Participant *participant,
		const char *addr, libnapc_u16 port
	);

	/*!
	 * @name napc_IPv4Participant_create
	 * @brief Create a participant object.
	 * @version 1.0.0
	 * @description
	 * Create a participant.
	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
	 * @param port Port of participant.
	 * @return Returns an initialized participant.
	 * @notes
	 * Input address (`addr`) will be copied into `participant`.
	 * @changelog 1.0.0 17.02.2022 initial version
	 * @example
	 * napc__IPv4Participant google_dns = napc_IPv4Participant_create("8.8.8.8", 53);
	 */
	libnapc__IPv4Participant libnapc_IPv4Participant_create(const char *addr, libnapc_u16 port);

	/*!
	 * @name napc_IPv4Participant_copy
	 * @brief Copy a participant.
	 * @version 1.0.0
	 * @description
	 * Create a copy of a participant.
	 * @param dest Pointer to destination.
	 * @param source Source.
	 * @todo make source a pointer too and add const?
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	void libnapc_IPv4Participant_copy(
		libnapc__IPv4Participant *dest,
		libnapc__IPv4Participant source
	);
#endif
