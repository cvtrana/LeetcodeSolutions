class Solution {
public:
    int Final = 0;
    int fun(TreeNode* root) {
        int ans = root->val;
        int left = 0, right = 0;
        if(root->left) {
            left = max(left, fun(root->left));
        }
        if(root->right) {
            right = max(right, fun(root->right));
        }
        ans += left + right;
        Final = max(Final, ans);
        return max(ans - left, ans - right);
    }
    int maxPathSum(TreeNode* root) {
        Final = root->val;
        fun(root);
        return Final;
    }
};