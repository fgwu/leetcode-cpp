class Solution {
public:
	/*after check with solution, try inline defined function*/
	/*20170520 1556*/
	/*         1600*/
	/*AC       1602*/
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<pair<int, int>> rv;
		auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)
			{return (a.first == b.first && a.second < b.second) || (a.first > b.first);};
		sort(people.begin(), people.end(), cmp);
		for (const auto & p:people)
			rv.insert(rv.begin() + p.second, p);
		return rv;
	}







	/*20170520 1514*/
	/*         1545*/
	/*AC       1549 bug: the scope of for-loop itr i; vector erase usage;*/
	// static bool compare_pair (pair<int, int> a, pair<int, int> b) {
	//     if (a.first != b.first) return a > b;
	//     return a.second < b.second;
	// }

	// vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	//     vector<pair<int, int>> rv(people.size());
	//     int ptr = people.size() - 1, i;
	//     sort(people.begin(), people.end(), compare_pair);
	//     while (people.size()) {
	//         for (i = people.size() - 1; i >= 0; i--)
	//             if (people[i].second == i) break;
	//         rv[ptr--] = people[i];
	//         people.erase(people.begin() + i);
	//     }
	//     return rv;
	// }
};
