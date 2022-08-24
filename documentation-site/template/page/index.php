<style>
div.landing {
	display: flex;
	align-items: center;
	justify-content: center;
	flex-direction: column;
}

div.landing h1 {
	font-size: 20px;
	font-weight: 400;
}

div.landing h1 i {
	color: rgba(255, 255, 255, .3);
	font-style: normal;
}

div.landing {
	max-width: 100%;
	max-height: 100%;
	overflow: hidden;
}

div.landing a {
	display: flex;
	align-items: center;
	justify-content: center;
	background-image: linear-gradient(15deg, #00A366, #0093F9);
	background-color: #00A366;
	font-size: 17px;
	padding: 7px 23px;
	border-radius: 40px;
	text-decoration: none;
	margin-top: 30px;
	z-index: 10;
	position: relative;
	text-shadow: 0px 2px 2px rgba(9, 8, 14, .35);
}

div.landing pre.code, div.landing pre.code2 {
	background: none !important;
	border: none !important;
	padding: none !important;
	position: absolute;
	transform: rotate(0deg); /* -25deg */
	font-size: 12px !important;
	top: 0px;
	line-height: 20px !important;
	color: rgba(255, 255, 255, .04);
}

div.landing pre.code2 {
	display: none;
	transform: rotate(25deg);
}
</style>
<div class="landing">

<pre class="code">
#if !defined(NAPC_MAGIC_h)
	#define NAPC_MAGIC_h

	#include &lt;libnapc.h&gt;

	#include &lt;napc-panic/napc-panic.h&gt;

	typedef uint32_t napc_init_magic;

	#define NAPC_MAGIC_MEMBER napc_init_magic _init_magic

	#define NAPC_MAGIC_DESTROYED NAPC_U32_LITERAL(0xFFFFFFFF)

	#define NAPC_MAGIC_INIT(type, obj) (obj)-&gt;_init_magic = (NAPC_MAGIC_ ## type)
	#define NAPC_MAGIC_DESTROY(obj) (obj)-&gt;_init_magic = NAPC_MAGIC_DESTROYED

	// Used to silence -Waddress warnings
	#define PV_NAPC_MAGIC_GET_VALUE(obj) \
		((void *)(obj) != NULL ? (obj)-&gt;_init_magic : 0)

	#define NAPC_MAGIC_ASSERT(type, obj)                                   \
		do {                                                               \
			const napc_init_magic actual   = PV_NAPC_MAGIC_GET_VALUE(obj); \
			const napc_init_magic expected = (NAPC_MAGIC_ ## type);        \
			if (actual == NAPC_MAGIC_DESTROYED) {                          \
				NAPC_PANIC(&quot;Attempt to use destroyed &quot; # type);            \
			} else if (actual != expected) {                               \
				NAPC_PANIC(&quot;Detected uninitialized &quot; # type);              \</pre>

<pre class="code2">
#include &lt;module/dns/_private/_dns.h&gt;

bool napc_DNS_parseRequest(
	napc__DNSRequest *out,
	const void *buffer, napc_size buffer_size
) {
	napc__DNSHeader header;

	if (!napc_DNS_parseHeader(&amp;header, buffer, buffer_size)) {
		return false;
	}

	napc__Reader reader;
	napc_Reader_init(&amp;reader, buffer, buffer_size);

	// skip DNS header we just read
	if (!napc_Reader_readU8Array(&amp;reader, 12, NULL)) return false;

	if (header.question_count != 1) {
		PV_NAPC_DNS_WARNING(
			&quot;Request contains other than 1 question (%d questions).&quot;, header.question_count
		);

		return false;
	}

	// question count capped at max 1
	napc__DNSQuery *q = out ? &amp;out-&gt;query : NULL;

	if (!PV_napc_DNS_parseQuerySection(q, &amp;reader)) {
		return false;
	}

	if (out) {
		memcpy(&amp;out-&gt;header, &amp;header, sizeof(header));
	}

	return true;
}
</pre>

<?php

echo napcdoc::html_createImageElement("big-c.png", [
	"height" => 300,
	"class" => "big-c"
]);
?>

<h1><i>Run, Test & Debug on Linux.</i> Deploy on Arduino.</h1>

<a href="document/1.gettingStarted.md.html">Jump right in!</a>
</div>
