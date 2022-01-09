string minimum_window(string s, string t) {
	int m[256] = {0};
	int ans = INT_MAX;
	int start = 0;
	int count = 0;

	//creating map
	for (int i = 0; i < t.length(); i++) {
		if (m[t[i]] == 0)
			count++;
		m[t[i]]++;
	}

	//reference of window
	int i = 0, j = 0;

	while (j < s.length()) {
		//calculations
		m[s[j]]--;
		if (m[s[j]] == 0)
			count--;

		//conditon matching
		if (count == 0) {
			while (count == 0) {
				if (ans > j - i + 1) {
					ans = min(ans, j - i + 1);
					start = i;
				}
				m[s[i]]++;
				if (m[s[i]] > 0)
					count++;

				i++;
			}
		}
		j++;
	}

	if (ans != INT_MAX)
		return s.substr(start, ans);
	else
		return "-1";
}