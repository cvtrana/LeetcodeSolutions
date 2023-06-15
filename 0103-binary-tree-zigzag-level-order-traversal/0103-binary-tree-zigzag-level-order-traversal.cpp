
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root==NULL){
            return results;
        }
        
        bool flag  = true;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            // traverse level wise and then insert 
            int n = q.size();
            vector<int> ans(n);
            for(int i=0;i<n;i++){
                TreeNode* temp =  q.front();
                q.pop();
                int index = flag?i:n-i-1;
                ans[index] = temp->val;
                
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right !=NULL){
                    q.push(temp->right);
                }
            }
            flag = !flag;
            results.push_back(ans);
            
        }
        return results;
        
    }
};