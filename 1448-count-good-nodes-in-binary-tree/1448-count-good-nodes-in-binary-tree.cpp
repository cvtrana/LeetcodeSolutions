
class Solution {
public:
    int nodes = 1;
    
    void rec(TreeNode* &root,int maxi){
        
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL){
            
            if(maxi > root->left->val){
                rec(root->left,maxi);
            }
            else{
                nodes++;
                rec(root->left,root->left->val);
                
            }
            
        }
        if(root->right!=NULL){
            if(maxi > root->right->val){
                rec(root->right,maxi);
            }
            else{
                nodes++;
                rec(root->right,root->right->val);
                
            }
            
        }
        
            
    }
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        rec(root,maxi);
        return nodes;
        
    }
};