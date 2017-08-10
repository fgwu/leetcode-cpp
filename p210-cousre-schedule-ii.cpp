class Solution {
public:
	/*DFS 1659*/
	/*AC  1708*/
	bool dfs (int curr, vector<vector<int>>& g, vector<int>& visited, vector<int>& res) {
		if (visited[curr] == 1) return false;
		if (visited[curr] == 2) return true;
		visited[curr] = 1;
		for (auto nbr: g[curr])
			if (!dfs(nbr, g, visited, res)) return false;

		visited[curr] = 2;
		res.push_back(curr);
		return true;
	}

	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> g(numCourses);
		vector<int> res;
		for (auto & p: prerequisites)
			g[p.second].push_back(p.first);

		vector<int> visited (numCourses, 0);

		for(int i = 0; i < numCourses; i++)
			if (!dfs(i, g, visited, res)) return vector<int>();

		reverse(res.begin(), res.end());
		return res;
	}

	/*20170810 1647*/
	/*Indegree AC 1658*/
	//     vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	//         vector<vector<int>> g(numCourses);
	//         vector<int> indegree(numCourses, 0);
	//         vector<int> res;
	//         for (auto & p: prerequisites) {
	//             g[p.second].push_back(p.first);
	//             indegree[p.first]++;
	//         }

	//         for (int i = 0; i < numCourses; i++)
	//             if (!indegree[i]) res.push_back(i);

	//         for (int i = 0; i < res.size(); i++)
	//             for (auto nbr: g[res[i]])
	//                 if (!--indegree[nbr]) res.push_back(nbr);

	//         if (res.size() == numCourses) return res;
	//         return vector<int>();
	//     }
};
