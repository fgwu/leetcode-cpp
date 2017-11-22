class Solution {
public:
	/*20171118 1901*/
	/*AC       1946*/
	string numberToWords(int num) {
		if (!num) return "Zero";
		vector<string> dm = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
				     "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
				     "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
		vector<string> tm = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

		if (num < 1000) {
			int tmp = num;
			int h = tmp / 100;
			tmp %= 100;
			if (tmp < 20) {
				return (h ? (dm[h] + " Hundred") : "") + (h && tmp ? " " : "") + dm[tmp];
			} else{
				int t = tmp / 10;
				tmp %= 10;
				int d = tmp;
				return (h ? (dm[h] + " Hundred") : "") + ((h && (t || d))? " " : "") + (t ? tm[t] : "")  + (d && tmp ? " " : "") + dm[d];
			}
		}

		int tmp = num;
		int num_billion = tmp / 1000000000;
		tmp %= 1000000000;
		int num_million = tmp / 1000000;
		tmp %= 1000000;
		int num_thousand = tmp / 1000;
		tmp %= 1000;
		return (num_billion ? (numberToWords(num_billion) + " Billion") : "") +
			((num_billion && (num_million || num_thousand || tmp))? " ": "") +
			(num_million ? (numberToWords(num_million) + " Million") : "") +
			((num_million && (num_thousand || tmp))? " " : "") +
			(num_thousand ? (numberToWords(num_thousand) + " Thousand") : "") +
			((num_thousand && tmp) ? " ": "") +
			(tmp ? numberToWords(tmp) : "");
	}
};
