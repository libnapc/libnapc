#if !defined(NAPC_MODULE_IPV4PARTICIPANT_h)
	#define NAPC_MODULE_IPV4PARTICIPANT_h

	#include <libnapc.h>
	#include <module/net/net.h>

	#include <napc-magic/napc-magic.h>

	/*!
	 * @name napc__IPv4Participant
	 * @brief Representation a network device.
	 * @version 1.0.0
	 * @description
	 * Representation of a participant in the internet protocol version 4 (IPv4).
	 * @field addr IPv4-Address as string in format `a.b.c.d`.
	 * @field port Port number.
	 * @changelog 1.0.0 17.02.2022 initial version
	 */
	typedef struct {
		NAPC_MAGIC_MEMBER;

		char addr[NAPC_MODULE_NET_IP_STR_MAX];
		napc_u16 port;
	} napc__IPv4Participant;

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
	void napc_IPv4Participant_init(
		napc__IPv4Participant *participant,
		const char *addr, napc_u16 port
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
	napc__IPv4Participant napc_IPv4Participant_create(const char *addr, napc_u16 port);

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
	void napc_IPv4Participant_copy(
		napc__IPv4Participant *dest,
		napc__IPv4Participant source
	);
#endif
