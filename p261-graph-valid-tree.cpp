class Solution {
public:
	/*AC   2113 union find*/
	int union_find(vector<int>& uf, int e) {
		while(e != uf[e]){
			int next = uf[e];
			uf[e] = uf[next];
			e = next;
		}
		return e;
	}

	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<int> uf(n);
		int union_cnt = n;
		for (int i = 0; i < n; i++)
			uf[i] = i;

		for (auto & p: edges){
			int n1 = union_find(uf, p.first);
			int n2 = union_find(uf, p.second);
			if(n1 == n2) return false;
			uf[n1] = n2;
			union_cnt--;
		}

		return union_cnt == 1;
	}

	/*20171126 2040*/
	/*AC       0905*/
	//     bool validTree(int n, vector<pair<int, int>>& edges) {
	//         vector<vector<int>> g(n, vector<int>(n, 0));
	//         vector<int> parents(n, -1);
	//         for (auto & p: edges)
	//             g[p.first][p.second] = g[p.second][p.first] = 1;

	//         queue<int>q;
	//         unordered_set<int> visited;
	//         q.push(0);

	//         while(!q.empty()) {
	//             int curr = q.front();
	//             if (visited.count(curr)) return false;
	//             visited.insert(curr);
	//             for(int i = 0; i < n; i++){
	//                 if (i == curr || i == parents[curr]) continue;
	//                 if (!g[curr][i]) continue;
	//                 parents[i] = curr;
	//                 q.push(i);
	//             }
	//             q.pop();
	//         }

	//         return visited.size() == n;
	//     }

};
