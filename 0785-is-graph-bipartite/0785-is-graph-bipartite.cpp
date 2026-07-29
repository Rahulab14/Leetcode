class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();

    // -1 = uncolored, 0 and 1 are the two colors
    vector<int> color(n, -1);

    // Handle disconnected graphs
    for (int start = 0; start < n; start++) {
        if (color[start] != -1)
            continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : graph[u]) {
                // Conflict: adjacent vertices have the same color
                if (color[v] == color[u])
                    return false;

                // Color the unvisited neighbor
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
    }

    return true;
}
};