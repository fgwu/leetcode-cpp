class Solution {
public:
/*20170614 2327*/
/*AC       2332*/
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while(i >= 0 && s[i] == ' ') i--;
        if (i < 0) return 0;
        int j = i - 1;
        while (j >= 0 && s[j] != ' ') j--;
        return i - j;
    }
};