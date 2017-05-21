class Solution {
public:
	/*20170520 1957*/
	/*         2350*/
	/*AC       0000*/
	double dfs(unordered_map<string, vector<pair<string, double>>> & graph,
		   pair<string, string> query, unordered_set<string> &visited) {
		if (graph.find(query.first) == graph.end()) return -1;
		if (query.first == query.second) return 1;
		for (const auto & nbr: graph[query.first]) {
			if (visited.count(nbr.first)) continue;
			visited.insert(nbr.first);
			double tmp = dfs(graph, make_pair(nbr.first, query.second), visited);
			if (tmp != -1) return tmp * nbr.second;
		}
		return -1;
	}

	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		int i;
		vector<double> rv;
		unordered_map<string, vector<pair<string, double>>> graph;
	for (i = 0; i < equations.size(); i++) {
		string v1 = equations[i].first, v2 = equations[i].second;
		double q = values[i];
		pair<string, double> new_edge = make_pair(v2, q);
		if (graph.find(v1) != graph.end())
			graph[v1].push_back(new_edge);
		else {
			vector<pair<string, double>> edge_list = {new_edge};
			graph[v1] = edge_list;
		}

		pair<string, double> new_edge2 = make_pair(v1, 1/q);
		if (graph.find(v2) != graph.end())
			graph[v2].push_back(new_edge2);
		else {
			vector<pair<string, double>> edge_list = {new_edge2};
			graph[v2] = edge_list;
		}
	}

	for (const auto & query: queries) {
		unordered_set<string> visited;
		rv.push_back(dfs(graph, query, visited));
	}

	return rv;
}
	};
