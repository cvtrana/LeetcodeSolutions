
class Solution {
public:
    int getHeight(TreeNode* root){
        // base case
        if(root->left == NULL && root->right==NULL){
            return 0;
        }
        int leftcall,rightcall;
        rightcall = 0;
        leftcall = 0;
        if(root->left!=NULL){
            leftcall = 1 +  getHeight(root->left);
            
        }
        if(root->right != NULL){
            rightcall = 1 + getHeight(root->right);
            
        }
        
        
        int ans =  max(leftcall,rightcall);
        return ans;
        
        
        
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int height = getHeight(root);
        return height+1;
        
        
    }
};