// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
	char tmp[4];
	int pos = 4;
	int bytes_read = 4;
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Maximum number of characters to read
	 * @return    The number of characters read
	 */

	/*AC   20171125 1004*/
	int read(char *buf, int n) {
		int nbytes = 0;

		if (pos < bytes_read) {
			nbytes += min(n, bytes_read - pos);
			strncpy(buf, tmp + pos, nbytes);
			pos += nbytes;
		}

		while(nbytes < n) {
			bytes_read = read4(tmp);
			pos = min(bytes_read, n - nbytes);
			strncpy(buf + nbytes, tmp, pos);
			nbytes += pos;
			if (bytes_read < 4) break;
		}
		return nbytes;
	}
};
