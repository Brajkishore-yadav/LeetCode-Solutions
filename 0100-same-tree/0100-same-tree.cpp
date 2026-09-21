class Solution {
public:
    bool temp(TreeNode* p, TreeNode* q) {

        // Dono NULL hain -> same
        if (p == NULL && q == NULL)
            return true;

        // Ek NULL hai aur doosra nahi -> different
        if (p == NULL || q == NULL)
            return false;

        // Values different -> different
        if (p->val != q->val)
            return false;

        // Dono subtrees bhi same hone chahiye
        return temp(p->left, q->left) &&
               temp(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return temp(p, q);
    }
};