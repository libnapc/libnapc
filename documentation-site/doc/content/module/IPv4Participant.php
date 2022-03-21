<p>
	To reduce parameter count this module is used to combine an IPv4-Address and a port number:
</p>

<pre class="code hljs">
// Holds address for google's DNS server 8.8.8.8:53
napc__IPv4Participant google_dns;

// Initialize google_dns variable
napc_IPv4Participant_init(&google_dns, "8.8.8.8", 53);
</pre>
