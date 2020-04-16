class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // pair - target node, weight
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const vector<int>& time : times) {
            edges[time[0]].emplace_back(time[1], time[2]);
        }
        // pair - negtive weight to(min heap), next node
        priority_queue<pair<int, int>> pq;
        int cur_wegiht = 0;
        pq.emplace(-cur_wegiht, K);
        vector<bool> visited(N + 1, false);
        while (N > 0 && !pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int node = cur.second;
            //multiple edges before visited!
            if (visited[node]) {
                continue;
            }
            cur_wegiht = -cur.first;
            visited[node] = true;
            N --;
            for (const pair<int, int> target : edges[node]) {
                int next_node = target.first;
                // wrong! multiple edges before visited! so this is not enough!
                if (visited[next_node]) {
                    continue;
                }
                int edge_weight = target.second;
                pq.emplace(-(cur_wegiht + edge_weight), next_node);
            }
        }
        return N == 0 ? cur_wegiht : -1;
    }
};
