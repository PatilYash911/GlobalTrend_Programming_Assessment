#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxPathSumRecursive(TreeNode *node, int &maxSum)
{
    if (node == nullptr)
    {
        return 0;
    }

    int leftPathSum = maxPathSumRecursive(node->left, maxSum);
    int rightPathSum = maxPathSumRecursive(node->right, maxSum);

    int maxPathThroughNode = node->val + max(0, leftPathSum) + max(0, rightPathSum);
    maxSum = max(maxSum, maxPathThroughNode);

    return node->val + max(0, max(leftPathSum, rightPathSum));
}

int maxPathSum(TreeNode *root)
{
    int maxSum = numeric_limits<int>::min();
    maxPathSumRecursive(root, maxSum);
    return maxSum;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl;
    return 0;
}
