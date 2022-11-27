/* <-- add '!' back once ported -->
 * @name IPv4Participant:intro
 * @description
 * To reduce parameter count this module is used to combine an IPv4-Address and a port number:
 * 
 * ```c
 * // Holds address for google's DNS server 8.8.8.8:53
 * libnapc__IPv4Participant google_dns;
 * 
 * // Initialize google_dns variable
 * libnapc_IPv4Participant_init(&google_dns, "8.8.8.8", 53);
 * ```
 */
#if !defined(LIBNAPC_MODULE_IPV4PARTICIPANT_h)
	#define LIBNAPC_MODULE_IPV4PARTICIPANT_h

	#include <libnapc-internal.h>

	#include <libnapc-magic/libnapc-magic.h>

	/*!
	 * Representation of a participant of the internet protocol version 4 (IPv4).
	 * 
	 * @module IPv4Participant
	 * @type type:struct
	 * @fullname libnapc__IPv4Participant
	 * @brief Representation a network device.
	 * @version 2.0.0
	 * @field addr IPv4-Address as string in format `a.b.c.d`.
	 * @field port Port number.
	 * @changelog 2.0.0 initial version
	 */
	typedef struct libnapc__IPv4Participant {
		LIBNAPC_MAGIC_MEMBER;

		char addr[32];
		libnapc_u16 port;
	} libnapc__IPv4Participant;

	/*!
	 * Initializes an IPv4 participant.
	 * 
	 * @module IPv4Participant
	 * @type fn
	 * @fullname libnapc_IPv4Participant_init
	 * @name init
	 * @brief Initialize a participant.
	 * @version 2.0.0
	 * @param participant Pointer to instance to initialize.
	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
	 * @param port Port of participant.
	 * @note
	 * Input address (`addr`) will be copied into `participant`.
	 * @changelog 2.0.0 initial version
	 */
	void libnapc_IPv4Participant_init(
		libnapc__IPv4Participant *participant,
		const char *addr, libnapc_u16 port
	);

	/*!
	 * Creates an IPv4 participant.
	 * 
	 * @module IPv4Participant
	 * @type fn
	 * @fullname libnapc_IPv4Participant_create
	 * @name create
	 * @brief Create a participant object.
	 * @version 2.0.0
	 * @param addr IPv4-Address of participant in format `a.b.c.d`.
	 * @param port Port of participant.
	 * @return Returns an initialized participant.
	 * @note
	 * Input address (`addr`) will be copied into `participant`.
	 * @changelog 2.0.0 initial version
	 * @example
	 * libnapc__IPv4Participant google_dns = libnapc_IPv4Participant_create("8.8.8.8", 53);
	 */
	libnapc__IPv4Participant libnapc_IPv4Participant_create(const char *addr, libnapc_u16 port);

	/*!
	 * Creates a copy of a participant.
	 * 
	 * @module IPv4Participant
	 * @type fn
	 * @fullname libnapc_IPv4Participant_copy
	 * @name copy
	 * @brief Copy a participant.
	 * @version 2.0.0
	 * @param dest Pointer to destination.
	 * @param source Source.
	 * @changelog 2.0.0 initial version
	 */
	// todo: make source a pointer too and add const?
	void libnapc_IPv4Participant_copy(
		libnapc__IPv4Participant *dest,
		libnapc__IPv4Participant source
	);
#endif
