
class Solution {
public:
    // check all the paths in the binary tree
    void solve(TreeNode* root, int &cnt , int k , vector<int> &paths){
        if(root==NULL){
            return;
        }
        
        // call left 
        paths.push_back(root->val);
        if(root->left!=NULL){
            // call the left subtree
            solve(root->left, cnt , k , paths);
        }
        
        if(root->right !=NULL){
            // call the right subtree
            solve(root->right, cnt, k , paths);
        }
        
        long long sum =0; //integer overflow
        int sz = paths.size();
        for(int i=sz-1;i>=0;i--){
            sum += paths[i];
            if(sum==k){
                cnt++;
                
            }
        }
        // pop_back the last element before going up
        paths.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> paths;
        int cnt=0;
        solve(root,cnt,targetSum,paths);
        
        return cnt;
        
    }
};