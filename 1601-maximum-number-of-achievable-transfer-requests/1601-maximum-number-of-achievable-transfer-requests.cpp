class Solution {
    int dfs(int i, vector<int> &indegree, vector<vector<int>> &requests) {
        if (i<0) {
            for (int num:indegree) {
                if (num!=0) return -1e9;
            }
            return 0;
        }
        indegree[requests[i][0]]--;
        indegree[requests[i][1]]++;
        int pick = 1 + dfs(i-1, indegree, requests);
        // backtrack
        indegree[requests[i][0]]++; 
        indegree[requests[i][1]]--;
        int notpick = dfs(i-1, indegree, requests);
        return max(pick, notpick);
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int reqs = requests.size();
        vector<int> indegree(n, 0);
        return dfs(reqs-1, indegree, requests);

    }
};