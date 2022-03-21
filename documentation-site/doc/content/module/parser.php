<p>
	This module contains all functions that parse strings.
</p>
<p>
	All functions in this module follow the same rules<sup>*</sup>:
</p>
<ul>
	<li>The first parameter is always the string to be parsed.</li>
	<li>Every function returns a boolean indicating success or failure.</li>
	<li>It is allowed to pass <code class="inline">NULL</code> as output. This is useful for checking the format of a string:</li>
</ul>

<pre class="code hljs">
if (napc_parser_parseIPv4Address(ip_str, NULL)) {
	// ip_str is a valid IPv4Address
}
</pre>

<ul>
	<li>If a function returned <code class="inline">false</code> the contents of the parsed output is <b>undefined</b>.</li>
</ul>

<p style="margin-top: 20px;font-size: 12px;">
	* The only exception being <code class="inline" style="font-size:12px">napc_parser_parseKeyValue()</code>.
</p>
