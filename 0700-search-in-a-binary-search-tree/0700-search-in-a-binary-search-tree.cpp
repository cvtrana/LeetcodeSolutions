
class Solution {
public:
    TreeNode* search(TreeNode* root,int val){
        if(root==NULL){
            return NULL;
        }
        if(root->val==val){
            return root;
        }
        if(val > root->val){
            return search(root->right,val);
            
        }
        else if(val < root->val){
            return search(root->left,val);
            
        }
        else{
            return root;
            
        }
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = NULL;
        if(root->val==val){
            return root;
        }
        if(root->val > val){
            temp  = search(root->left,val);
            
        }
        else{
            temp = search(root->right,val);
            
        }
        return temp;
        
        
    }
};