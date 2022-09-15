<?php

return function() {
	$build_constants = napcdoc::site_getDocumentation()["build_constants"];

	$xml_response  = '<?xml version="1.0" encoding="UTF-8"?>'."\n";
	$xml_response .=  '<metadata>'."\n";
	$xml_response .=  "\t".'<build_constants>'."\n";

	foreach ($build_constants as $key => $value) {
		// skip BUILD_DATE
		if ($key === "BUILD_DATE") continue;

		$xml_response .=  "\t\t".'<build_constant>'."\n";
		$xml_response .=  "\t\t\t".'<name>'.$key.'</name>'."\n";
		$xml_response .=  "\t\t\t".'<value>'.$value.'</value>'."\n";
		$xml_response .=  "\t\t".'</build_constant>'."\n";
	}

	$xml_response .=  "\t".'</build_constants>'."\n";

	$release_files = napcdoc::site_getDocumentation()["files"];

	$xml_response .=  "\t".'<release_files>'."\n";

	foreach ($release_files as $filename => $meta) {
		$xml_response .=  "\t\t".'<release_file>'."\n";
		$xml_response .=  "\t\t\t<name>".$filename."</name>\n";
		$xml_response .=  "\t\t\t<size>".$meta["size"]."</size>\n";
		$xml_response .=  "\t\t\t<checksum>".$meta["checksum"]."</checksum>\n";
		$xml_response .=  "\t\t".'</release_file>'."\n";
	}

	$xml_response .=  "\t".'</release_files>'."\n";
	$xml_response .=  '</metadata>'."\n";

	return $xml_response;
};
