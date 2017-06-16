class Solution {
public:
	/*20170615 0013*/
	/*AC       0027*/
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < flowerbed.size(); i++) {
			if (flowerbed[i]) continue;
			if (i - 1 >= 0 && flowerbed[i - 1]) continue;
			if (i + 1 < flowerbed.size() && flowerbed[i + 1]) continue;
			flowerbed[i] = 1;
			cout << i << flowerbed[i + 1] << "\n";
			n--;
		}
		return n <= 0;
	}
};
