# Home

Thank you very much for checking out the documentation of [libnapc](https://libnapc.nap-software.com/)! 🎉

This library came into existence to support any projects written in C by nap.software.

Its split up into three parts:

- Core library (basic functionality, basic HAL)
- Hardware independent modules:
  - DNS
  - Cryptographic functions (SHA256-HMAC and AES-256)
  - Buffer management (Writer, Reader)
  - Random byte generation
  - String parsing
- Hardware dependent modules:
  - Networking (UDP)
  - FileSystem

It provides HAL (Hardware Abstraction Layer) so that applications written in it can be run both on Arduino and Linux.

<div class="content-box color-orange">
	<div class="content-box-head">
		<div>Caution</div>
	</div>
	<div class="content-box-content">
		<p>For all versions starting with 1.x.x (e.g. 1.5.30) API is not stable, anticipate breaking changes with any new release.</p>
		<p>First version starting with 2.x.x will be stable and follow <a href="https://semver.org/" target="_blank">semantic versioning</a>.</p>
	</div>
</div>
