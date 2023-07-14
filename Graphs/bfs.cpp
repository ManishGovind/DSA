class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> visited(V);
        queue<int> q;
        if (sizeof(adj) == 0) return res;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {

            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (auto it : adj[curr]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }

        }
        return res;
    }
};