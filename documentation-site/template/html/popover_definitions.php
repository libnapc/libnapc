<?php

return function($keys) {
	foreach (napcdoc::documentation_getRegisteredPopovers() as $definition_name) {
		$definition = napcdoc::documentation_getDefinition($definition_name);

		echo '<div style="display: none;" data-code-definition="'.$definition_name.'">';

		if ($definition["type"] === "fn") {
			echo napcdoc::formatting_proto_fn($definition_name);
		} else if ($definition["type"] === "type") {
			echo napcdoc::formatting_proto_type($definition_name);
		} else {
			echo "UNKNOWN";
		}

		echo '</div>'."\n";
	}
};
