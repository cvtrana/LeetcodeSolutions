
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // basecase
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==p->val || root->val==q->val){
            return root; 
        }
        
        TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
        
        if(leftans!= NULL && rightans !=NULL){
            return root; // ans mil gya , nachooo
        }
        else if(leftans!=NULL && rightans==NULL){
            return leftans;
        }
        else if(rightans!=NULL && leftans==NULL){
            return rightans;
        }
        else{
            return NULL;
        }
        
    }
};