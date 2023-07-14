/*
dfs of graph
*/

class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int v, vector<int> adj[], vector<bool>& visited, vector<int>& res) {
        res.push_back(v);
        visited[v] = true;
        for (auto it : adj[v]) {
            if (!visited[it]) {
                dfs(it, adj, visited, res);
            }
        }
    }


    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<bool> visited(V, false);

        dfs(0, adj, visited, res);
        return res;
    }
};