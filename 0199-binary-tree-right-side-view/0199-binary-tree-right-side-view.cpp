// node -val
class Solution {
public:
    void solve(TreeNode* root,vector<int> &ans,int lev){
        // base case
        if(root==NULL){
            return;
        }
        
        // checking if the level increases
        if(lev == ans.size()){
            ans.push_back(root->val);
        }
        // calling the right side 
        solve(root->right,ans,lev+1);
        solve(root->left,ans,lev+1);
        
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0); // initial level  = 0;
        return ans;
        
    }
};