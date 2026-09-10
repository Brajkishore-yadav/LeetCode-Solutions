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

    // Ye function current node ke subtree ka
    // {total sum, total nodes} return karega
    pair<int, int> dfs(TreeNode* root, int &ans) {

        // Agar node NULL hai to:
        // sum = 0, count = 0
        if (root == nullptr) {
            return {0, 0};
        }

        // Pehle left subtree ka sum aur count nikaalo
        auto left = dfs(root->left, ans);

        // Phir right subtree ka sum aur count nikaalo
        auto right = dfs(root->right, ans);

        // Current node + left subtree + right subtree
        // ka total sum
        int sum = root->val + left.first + right.first;

        // Total nodes:
        // 1 = current node
        // left.second = left subtree ke nodes
        // right.second = right subtree ke nodes
        int count = 1 + left.second + right.second;

        // Subtree ka average nikaalo
        // C++ integer division ki wajah se decimal part
        // automatically remove ho jayega (floor)
        int average = sum / count;

        // Agar average current node ki value ke equal hai
        // to answer mein 1 add karo
        if (average == root->val) {
            ans++;
        }

        // Current subtree ka total sum aur total count
        // parent node ko return karo
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {

        // Answer store karne ke liye
        int ans = 0;

        // Root se DFS start karo
        dfs(root, ans);

        // Final answer return karo
        return ans;
    }
};