class Solution {
private:
  void uncoverCycle(unordered_map<int, unordered_set<int>>& graph) {
    int n = graph.size();
    vector<int> remove = {};
    for (auto& kv : graph) {
      int node = kv.first;
      auto& adjlist = kv.second;
      if (adjlist.size() == 1) { // leaf node
        remove.push_back(node);
        auto it = adjlist.begin();
        graph[*it].erase(node);
      }
    }

    if (remove.empty()) return;
    else {
      for (int node : remove) graph.erase(node);
      uncoverCycle(graph);
    }
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_map<int, unordered_set<int>> graph;
    for (int i = 0; i < n; ++i) { // undirected graph
      graph[edges[i][0]].insert(edges[i][1]);
      graph[edges[i][1]].insert(edges[i][0]);
    }

    // recursively remove leaf nodes to uncover the cycle
    uncoverCycle(graph);

    for (int i = n - 1; i >= 0; --i) {
      if (graph.count(edges[i][0]) && graph.count(edges[i][1])) return edges[i];
    }

    return {};
  }
};