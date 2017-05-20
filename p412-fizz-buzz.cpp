class Solution {
public:
	/*20170517 14:20*/
	/*         14:26*/
	/*AC       14:27*/
	vector<string> fizzBuzz(int n) {
		int i;
		vector<string> rv;
		for (int i = 1; i <= n; i++){
			if (i%3==0 && i%5==0) {
				rv.push_back("FizzBuzz");
				continue;
			}
			if (i%3 == 0) {
				rv.push_back("Fizz");
				continue;
			}
			if (i%5== 0) {
				rv.push_back("Buzz");
				continue;
			}

			rv.push_back(to_string(i));

		}
		return rv;
	}
};
