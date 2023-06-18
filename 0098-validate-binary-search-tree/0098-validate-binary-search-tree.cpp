class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
private:
    bool valid(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }
        if (root -> val <= min || root -> val >= max) {
            return false;
        }
        return valid(root -> left, min, root -> val) && valid(root -> right, root -> val, max);
    }
};