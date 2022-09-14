window.napcdoc.lib.localStorageSet = function(key, value) {
	try {
		window.localStorage.setItem(key, value)
	} catch (error) {}
}
