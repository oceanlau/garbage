class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < ppid.size(); i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        int kill_its_child = -1;
        m[kill_its_child].push_back(kill);
        stack<pair<int, int>> st;
        while (m.count(kill_its_child)) {
            st.emplace(kill_its_child, 0);
            kill_its_child = m[kill_its_child][0];
        }
        vector<int> killed;
        while (!st.empty()) {
            pair<int, int> cur = st.top();
            st.pop();
            killed.push_back(m[cur.first][cur.second]);
            if (m[cur.first].size() > cur.second + 1) {
                st.emplace(cur.first, cur.second + 1);
                kill_its_child = m[cur.first][cur.second + 1];
                while (m.count(kill_its_child)) {
                    st.emplace(kill_its_child, 0);
                    kill_its_child = m[kill_its_child][0];
                }
            }
        }
        return killed;
    }
};
