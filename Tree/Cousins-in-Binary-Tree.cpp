/*

Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.
*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        queue<TreeNode*> q;
        q.push(root);
        bool flag1 = false, flag2 = false;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && curr->right) {
                    if ((curr->left->val == x and curr->right->val == y) ||
                        (curr->left->val == y and curr->right->val == x))
                    {
                        return false;                // same parent
                    }
                }
                if (curr->val == x) flag1 = true;
                if (curr->val == y) flag2 = true;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

            }
            if (flag1 && flag2) {
                return true;
            }
            flag1 = false, flag2 = false;
        }

        return false;
    }
};