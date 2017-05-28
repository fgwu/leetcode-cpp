class Solution {
public:
	int romanToInt(string s) {
		char prev = '\0';
		int rv = 0;
		for (const auto & c:s) {
			switch(c) {
			case 'I':
				rv += 1;
				break;
			case 'V':
				rv += 5;
				if (prev == 'I') rv -= 2;
				break;
			case 'X':
				rv += 10;
				if (prev == 'I') rv -= 2;
				break;
			case 'L':
				rv += 50;
				if (prev == 'X') rv -= 20;
				break;
			case 'C':
				rv += 100;
				if (prev == 'X') rv -= 20;
				break;
			case 'D':
				rv += 500;
				if (prev == 'C') rv -= 200;
				break;
			case 'M':
				rv += 1000;
				if (prev == 'C') rv -= 200;
				break;
			default:
				return 0; // should not happen
			}
			prev = c;
		}
		return rv;
	}
};
