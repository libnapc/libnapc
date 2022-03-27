<div class="module-intro">
	<p>This library came into existence to support any projects written in C by <a href="https://nap.software" target="_blank">nap.software</a>.</p>
	<p>Its split up into three parts:</p>
	<ul>
		<li>Core library (basic functionality, basic HAL)</li>
		<li>Hardware independent modules:
			<ul>
				<li>DNS</li>
				<li>Cryptographic functions (SHA256-HMAC and AES-256)</li>
				<li>Buffer management (Writer, Reader)</li>
				<li>Random byte generation</li>
				<li>String parsing</li>
			</ul>
		</li>
		<li>Hardware dependent modules:
			<ul>
				<li>Networking (UDP)</li>
				<li>FileSystem</li>
			</ul>
		</li>
	</ul>

	<p>It provides HAL (Hardware Abstraction Layer) so that applications written in it can be run both on Arduino and Linux.</p>

	<div class="info-box">
		<?php echo napcdoc::createSVGElement("alert", 24, 24); ?>
		<div>
			This library is developed on a <i>per-need</i> basis. It is <b>not</b> a complete library (yet?).
		</div>
	</div>

	<!--
	<h2>Icon Legend</h2>

	<p>
		Throughout this documentation some icons are used:
	</p>

	<style>
		div.flex-table.icon-legend div.flex-table-row-cell:nth-child(1) {
			flex-basis: 100px;
		}
		div.flex-table.icon-legend div.flex-table-row-cell:nth-child(2) {
			flex-basis: 120px;
		}
	</style>

	<div class="flex-table icon-legend">
		<div class="flex-table-row">
			<div class="flex-table-row-cell">Icon</div>
			<div class="flex-table-row-cell">Scope</div>
			<div class="flex-table-row-cell">Meaning</div>
		</div>

		<div class="flex-table-row">
			<div class="flex-table-row-cell"><?=napcdoc::createSVGElement("type_icon/fn", 20, 20, ["data-definition-type-icon" => "fn"]);?></div>
			<div class="flex-table-row-cell">Definitions</div>
			<div class="flex-table-row-cell"><div>This is a <b>function</b> definition.</div></div>
		</div>

		<div class="flex-table-row">
			<div class="flex-table-row-cell"><?=napcdoc::createSVGElement("type_icon/outline/type", 20, 20, ["data-definition-type-icon" => "type"]);?></div>
			<div class="flex-table-row-cell">Definitions</div>
			<div class="flex-table-row-cell"><div>This is a <b>type</b> definition.</div></div>
		</div>

		<div class="flex-table-row">
			<div class="flex-table-row-cell"><?=napcdoc::createSVGElement("type_icon/filled/macro", 20, 20, ["data-definition-type-icon" => "macro"]);?></div>
			<div class="flex-table-row-cell">Definitions</div>
			<div class="flex-table-row-cell"><div>This is a <b>macro</b> definition.</div></div>
		</div>

		<div class="flex-table-row">
			<div class="flex-table-row-cell"><?=napcdoc::createSVGElement("type_icon/outline/struct", 20, 20, ["data-definition-type-icon" => "type"]);?></div>
			<div class="flex-table-row-cell">Types</div>
			<div class="flex-table-row-cell"><div>This is a struct, you are free to access and modify any structural members.</div></div>
		</div>

		<div class="flex-table-row">
			<div class="flex-table-row-cell"><?=napcdoc::createSVGElement("type_icon/filled/struct", 20, 20, ["data-definition-type-icon" => "type"]);?></div>
			<div class="flex-table-row-cell">Types</div>
			<div class="flex-table-row-cell"><div>This is an <b>opaque</b> struct, do not access or modify any structural members.</div></div>
		</div>
	</div>

-->
</div>
