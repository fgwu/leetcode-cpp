class Solution {
public:
	/*20170809 2126 deleting nodes of indegree=0*/
	/*AC       2134*/
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> g(numCourses);
		vector<int> indegree(numCourses, 0);
		for (auto & pair: prerequisites) {
			g[pair.second].push_back(pair.first);
			indegree[pair.first]++;
		}

		queue<int> q;
		int cnt = 0;
		for(int i = 0; i < numCourses; i++)
			if (!indegree[i]) q.push(i);

		while(!q.empty()) {
			int node = q.front();
			q.pop();
			cnt++;
			for (auto nbr: g[node])
				if (--indegree[nbr] == 0)
					q.push(nbr);
		}

		return cnt == numCourses;

	}



	/*20170807 0154 cycle detection*/
	/*20170809 restart*/
	//     /*AC       0749*/
	//     bool dfs(vector<vector<int>>& g, vector<int>& visited, int start) {
	//         if (visited[start] == 1) return false;
	//         visited[start]++;
	//         for (auto nbr: g[start]) {
	//             if (visited[nbr] == 2) continue;
	//             if (!dfs(g, visited, nbr)) return false;
	//         }
	//         visited[start]++;
	//         return true;
	//     }

	//     bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	//         vector<vector<int>> g (numCourses);
	//         for (auto & p: prerequisites)
	//             g[p.second].push_back(p.first);
	//         vector<int> visited (numCourses, 0);

	//         for (int i = 0; i < numCourses; i++) {
	//             if (visited[i]) continue;
	//             if (!dfs(g, visited, i)) return false;
	//         }

	//         return true;
	//     }
};
