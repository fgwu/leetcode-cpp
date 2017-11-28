// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
	/**
	 * @param buf Destination buffer
	 * @param n   Maximum number of characters to read
	 * @return    The number of characters read
	 */
	/*20171122 0722*/
	/*AC       0736*/
	int read(char *buf, int n) {
		int nbytes = 0, nread;
		while(nbytes + 4 <= n) {
			nread = read4(buf + nbytes);
			nbytes += nread;
			if (nread < 4) return nbytes;
		}

		char smallbuf[4];
		nread = read4(smallbuf);
		int i;
		for(i = 0; nbytes < n && i < nread; i++, nbytes++)
			buf[nbytes] = smallbuf[i];

		return nbytes;
	}
	//  ....|....|???|
	//
};
