class Solution {
public:

    int ans = 0;

    pair<int, int> solve(TreeNode* root) {

        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = solve(root->left);

        pair<int, int> right = solve(root->right);

        int sum = left.first + right.first + root->val;

        int nodes = left.second + right.second + 1;

        int avg = sum / nodes;

        if (root->val == avg) {
            ans++;
        }

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {

        solve(root);

        return ans;
    }
};