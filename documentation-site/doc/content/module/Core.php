<p>
	Thank you very much for checking out the documentation of libnapc! 🎉
</p>

<p>
	Every napc application using libnapc defines <i>at least</i> these two functions:
</p>

<ul>
	<li><code class="inline">napc_app_setup()</code></li>
	<li><code class="inline">napc_app_loop()</code></li>
</ul>

<h2>Purpose of napc_app_setup</h2>

<p>
	Inspired by Arduino's <code class="inline">setup()</code> function libnapc uses the same methodology.
</p>

<p>
	You can use <code class="inline">napc_app_setup()</code> to perform initialisation that only needs to be done once in the program's lifecycle.
</p>

<p>
	<code class="inline">napc_app_setup()</code> also provides the current platform as a string:
</p>

<ul>
	<li><code class="inline">"arduino"</code> for Arduino.</li>
	<li><code class="inline">"linux"</code> for Linux.</li>
</ul>

<h2>The napc_app_loop function</h2>

<p>
	The <code class="inline">napc_app_loop</code> function gets called indefinitely until it returns <code class="inline">false</code> indicating the program should exit.
</p>

<h2>The most basic program possible</h2>

<pre class="code hljs">
#include &lt;napc.h&gt;

void napc_app_setup(const char *platform) {
	// do one time initialization here
	// like setting network adapter settings (napc_eth_)
}

bool napc_app_loop(napc_time uptime) {
	/* program logic */

	return true;
}
</pre>
