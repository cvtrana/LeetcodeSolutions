class Solution {
public:
    class Node{
        public:
        int data;
        int row;
        int col;
        Node(int d, int r,int c){
            data = d;
            row = r;
            col = c;
        }
    };
    class cmp{
        public:
        bool operator()(Node* a, Node* b){
            return  a->data > b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mini = INT_MAX,maxi = INT_MIN;
        priority_queue<Node*,vector<Node*>,cmp> pq;
        
        for(int i=0;i<nums.size();i++){
            int element = nums[i][0];
            mini = min(mini,element);
            maxi = max(maxi,element);
            pq.push(new Node(element,i,0));
        }
        int start = mini;
        int end = maxi;
        
        while(!pq.empty()){
            Node* temp = pq.top();
            pq.pop();
            mini = temp->data;
            
            // update the range
            
            if(maxi - mini < end - start){
                start = mini;
                end =  maxi;
            }
            
            if(temp->col + 1 < nums[temp->row].size()){
                maxi  = max(maxi,nums[temp->row][temp->col+1]);
                pq.push(new Node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
                
            }
            else{
                break;
            }
            
            
        }
        
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
        
        
        
        
        
    }
};