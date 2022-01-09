//Manachar's algorithm is used to find the longest palindromic substring

//brute force approach--O(N^3)
bool ispalindrome(string s) {
	int l = 0, r = s.length() - 1;
	while (l <= r && s[l] == s[r]) {
		l++;
		r--;
	}
	return l >= r;
}

string longestPalindrome(string s) {
	if (ispalindrome(s)) return s;
	for (int len = s.length() - 1; len > 0; len--) {
		for (int i = 0; i + len <= s.length(); i++) {
			if (ispalindrome(s.substr(i, i + len)))
				return s.substr(i, i + len);
		}
	}
	return "";
}


//optimised algo O(N^2)
string expandPalindrom(string s, int l, int r) {
	while (l >= 0 and r < s.length() && s[l] == s[r]) {
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {

	string lps = "";
	int n = s.length();
	for (int i = 0; i < n; i++) {
		//odd length
		string odd = expandPalindrom(s, i, i);
		string even = expandPalindrom(s, i, i + 1);

		if (lps.length() < odd.length())
			lps = odd;

		if (lps.length() < even.length())
			lps = even;

	}
	return lps;
}

//Manachar's algo--O(N)