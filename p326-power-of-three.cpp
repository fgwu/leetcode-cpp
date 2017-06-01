class Solution {
public:
	/*AC 20170601 1742*/
	/* sln shows that we can use 3^19 to divide n. Boring.. */
	bool isPowerOfThree(int n) {
		//        1 3 9 27 81 243 729
		//        0 2 8 24 80
		if (n <= 0) return false;
		if (n == 1) return true;
		if ( n%3 ) return false;
		return isPowerOfThree(n/3) ;
	}
};
