window.napcdoc.lib.localStorageGet = function(key, fallback) {
	try {
		let tmp = window.localStorage.getItem(key)

		if (!tmp.toString().length) {
			return fallback
		}

		return tmp
	} catch (error) {}

	return fallback
}
