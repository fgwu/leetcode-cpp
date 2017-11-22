/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	/*20171119 2328*/
	/*AC       2341*/
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m) {
		if (!node) return nullptr;

		UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
		m[node] = newnode;

		for(auto n: node->neighbors) {
			if (m.count(n))
				newnode->neighbors.push_back(m[n]);
			else
				newnode->neighbors.push_back(cloneGraph(n, m ));
		}

		return newnode;
	}


	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>m;
		return cloneGraph(node, m);
	}
};
