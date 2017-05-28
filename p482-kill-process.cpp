class Solution {
public:

	/*20170523 1542 rec version*/
	/*AC       1547*/

	void killRec(unordered_map<int, vector<int>> &m, int kill, vector<int> & res){
		res.push_back(kill);
		if (m.find(kill) == m.end()) return;
		for (const auto & n:m[kill]) killRec(m, n, res);
	}

	vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
		unordered_map<int, vector<int>> m;
		vector<int> res;
		for (int i = 0; i < ppid.size(); i++) m[ppid[i]].push_back(pid[i]);
		killit(m, res, kill);
		return res;
	}






	/*20170523 1513*/
	/*AC       1539*/
	//     vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	//         unordered_map<int, vector<int>> m;
	//         vector<int> res;
	//         for (int i = 0; i < ppid.size(); i++) {
	//             int parent = ppid[i];
	//             if (m.find(parent) == m.end())
	//                 m[parent] = vector<int>(1,pid[i]); // add child to list
	//             else
	//                 m[parent].push_back(pid[i]);
	// //            cout << parent << ": " << pid[i] << " " << m[parent].size() << "\n";

	//         }

	//         queue<int> q;
	//         q.push(kill);

	//         for (; !q.empty(); q.pop()) {
	//             int proc = q.front();
	//             res.push_back(proc);
	//             if (m.find(proc) == m.end()) continue;
	//             for (const auto & child: m[proc]) {
	//                 q.push(child);
	// //                cout << proc << ": " << child << "\n";
	//             }
	//         }

	//         return res;
	//     }


	/*20170523 1436*/
	/*         1513 time limit*/
	// vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
	//     vector<int> res;
	//     if (find(pid.begin(), pid.end(), kill) == pid.end()) return res;

	//     queue<int> q;
	//     q.push(kill);

	//     for(; !q.empty(); q.pop()){
	//         int val = q.front();
	//         //cout << val << ":";
	//         res.push_back(val);

	//         for(auto it = find(ppid.begin(), ppid.end(), val);
	//                     it != ppid.end();
	//                     it = find(it + 1, ppid.end(), val)) {
	//             q.push(pid[it - ppid.begin()]);
	//             //cout << " " << pid[it - ppid.begin()];
	//         }
	//         //cout << "\n";
	//     }

	//     return res;
	// }
};
