class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj;
        vector<string> ans;
        int n=tickets.size();
        //Make graph
        for(int i=0;i<n;++i)
            adj[tickets[i][0]].insert(tickets[i][1]);
        
        stack<string> mystack;
        mystack.push("JFK");    //JFK is our fixed starting point
        while(!mystack.empty())
        {
            string src = mystack.top();
            if(adj[src].size()==0)  //No further travel possible
            {
                ans.push_back(src);
                mystack.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                mystack.push(*dst);
                adj[src].erase(dst);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
        
        
        
        
        
    
};