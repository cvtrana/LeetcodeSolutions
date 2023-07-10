
class Solution {
public:
    int dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        int l = 1e9;
        int r = 1e9;
        
        if(root->left!=NULL){
            l = 1 + dfs(root->left);
        }
        if(root->right !=NULL){
            r = 1 + dfs(root->right);
        }
        return min(l,r);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans = dfs(root);
        return ans+1;
    }
};