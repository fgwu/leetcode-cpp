class Solution {
public:
	/*20171108 0635 sln*/
	/*AC       0640*/
	string intToRoman(int num) {
		vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		vector<string> M = {"", "M", "MM", "MMM"};

		return M[num/1000] + C[num%1000/100] + X[num%100/10] + I[num%10];
	}
	//     /*20171108 0604*/
	//     /*         0628*/
	//     /*AC       0631*/
	//     string intToRoman(int num) {
	//         string rv = "";
	//         int tmp = num / 1000;
	//         switch (tmp) {
	//             case 0:
	//             case 1:
	//             case 2:
	//             case 3:
	//                 while (tmp--) rv += "M";
	//                 break;
	//             default:
	//                 assert(0);
	//         }

	//         num %= 1000;
	//         tmp = num / 100;
	//         if (tmp >= 5 && tmp != 9) {
	//             rv += "D";
	//             tmp -= 5;
	//         }
	//         switch (tmp) {
	//             case 0:
	//             case 1:
	//             case 2:
	//             case 3:
	//                 while (tmp--) rv += "C";
	//                 break;
	//             case 4:
	//                 rv += "CD";
	//                 break;
	//             case 9:
	//                 rv += "CM";
	//                 break;
	//             default:
	//                 assert(0);
	//         }

	//         num %= 100;
	//         tmp = num / 10;

	//         if (tmp >= 5 && tmp != 9) {
	//             rv += "L";
	//             tmp -= 5;
	//         }
	//         switch(tmp) {
	//             case 0:
	//             case 1:
	//             case 2:
	//             case 3:
	//                 while (tmp--) rv += "X";
	//                 break;
	//             case 4:
	//                 rv += "XL";
	//                 break;
	//             case 9:
	//                 rv += "XC";
	//                 break;
	//             default:
	//                 assert(0);
	//         }

	//         num %= 10;
	//         if (num >= 5 && num != 9) {
	//             rv += "V";
	//             num -= 5;
	//         }
	//         switch(num) {
	//             case 0:
	//             case 1:
	//             case 2:
	//             case 3:
	//                 while (num--) rv += "I";
	//                 break;
	//             case 4:
	//                 rv += "IV";
	//                 break;
	//             case 9:
	//                 rv += "IX";
	//                 break;
	//             default:
	//                 assert(0);
	//         }

	//         return rv;
	//     }
};
