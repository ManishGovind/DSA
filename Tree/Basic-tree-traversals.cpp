/*
Tree Traversals

*/


/*
Inorder Trversal
*/
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};


/*preorder Trversal*/

class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return res;
    }

};

/*
postorder Traversal
*/

class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;

    }
};


/*level order Traversal*/


class Solution
{
public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        //Your code here
        vector<int>res;
        if (node == NULL)return res;
        queue<Node*>q;
        q.push(node);


        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            res.push_back(curr->data);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);

        }

        return res;
    }
};




/*reverse level order Traversal */

vector<int> reverseLevelOrder(Node* root)
{
    vector<int>ans;
    stack<Node*>s;
    queue<Node*>q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        ans.push_back(curr->data);
        q.pop();

        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }

    // while(!s.empty()){
    //     root = s.top();
    //     ans.push_back(root->data);
    //     s.pop();
    // }
    reverse(ans.begin(), ans.end());
    return ans;
}


/*
Zigzag Traversal 
*/


class Solution {
public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        // Code here
        vector<int> ans;
        queue<Node*> q;
        if (root == NULL) return ans;
        q.push(root);
        bool level = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                v.push_back(curr->data);
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (!level) {
                reverse(v.begin(), v.end());
            }

            level = !level;
            for (auto i : v) {
                ans.push_back(i);
            }

        }

        return ans;

    }
};

/*spiral traversal*/


vector<int> findSpiral(Node* root)
{
    // Code here
    vector<int> ans;
    queue<Node*> q;
    if (root == NULL) return ans;
    q.push(root);
    bool level = true;
    while (!q.empty()) {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            v.push_back(curr->data);
            q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        if (level) {
            reverse(v.begin(), v.end());
        }

        level = !level;
        for (auto i : v) {
            ans.push_back(i);
        }

    }

    return ans;
}
