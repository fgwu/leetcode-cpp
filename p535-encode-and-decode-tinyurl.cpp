class Solution {
	/*20170519 15:49*/
	/*AC       15:58*/
public:
	unordered_map<string, string> hash;
	int cnt = 0;
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		string rv = to_string(cnt++);
		hash[rv] = longUrl;
		return rv;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return hash[shortUrl];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
