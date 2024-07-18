#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize(TreeNode *root)
{
    if (!root)
        return "null";

    string result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            result += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            result += "null,";
        }
    }

    result.pop_back();

    return result;
}

TreeNode *deserialize(string data)
{
    if (data == "null")
        return nullptr;

    stringstream ss(data);
    string item;
    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (getline(ss, item, ','))
        {
            if (item != "null")
            {
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }
        }

        if (getline(ss, item, ','))
        {
            if (item != "null")
            {
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
    }

    return root;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedTree = serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode *deserializedRoot = deserialize(serializedTree);
    cout << "Deserialized Tree (In-Order): ";
    printTree(deserializedRoot);
    cout << endl;

    return 0;
}
