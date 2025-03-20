class Solution {
public:
    int getComponentCost(int node, vector<vector<pair<int, int>>>& adjList,vector<bool>& visited, vector<int>& components,int componentId) {
        int currentCost = INT_MAX;

        components[node] = componentId;
        visited[node] = true;

        for (auto& [neighbor, weight] : adjList[node]) {
            currentCost &= weight;

            if (!visited[neighbor]) {
                currentCost &= getComponentCost(neighbor, adjList, visited,components, componentId);
            }
        }
        return currentCost;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);

        vector<int> components(n);
        vector<int> componentCost;

        int componentId = 0;

        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                componentCost.push_back(getComponentCost(node, adjList, visited,   components, componentId));
                componentId++;
            }
        }

        vector<int> answer;

        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            if (components[start] == components[end]) {
                answer.push_back(componentCost[components[start]]);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};