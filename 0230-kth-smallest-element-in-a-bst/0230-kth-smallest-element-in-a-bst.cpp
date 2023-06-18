
class Solution {
public:
    vector<int> nodes;
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* temp = q.front();
                q.pop();
                nodes.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
        }
        sort(nodes.begin(),nodes.end());
        int pos = k-1;
        return nodes[pos];
    }
};