class Solution {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
               
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};