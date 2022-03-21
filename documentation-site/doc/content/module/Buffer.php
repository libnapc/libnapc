<p>
	To reduce parameter count this module is used to pass a buffer with its size to a function:
</p>

<pre class="code hljs">
char data[512];
napc__Buffer buffer;

napc_Buffer_init(&buffer, data, sizeof(data));
</pre>
