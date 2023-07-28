/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<string>& v,string s)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            s+=(to_string(root->val));
            v.push_back(s);
            return;
        }
        //s.push_back(to_string(root->val));
        //s.push_back("->");
        solve(root->left,v,s+to_string(root->val)+"->");
        solve(root->right,v,s+to_string(root->val)+"->");
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string s;
        if(root==NULL)
        {
            return v;
        }
        solve(root,v,s);
        return v;
    }
};