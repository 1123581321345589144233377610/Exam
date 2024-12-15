#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>


struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

void FindPath(TreeNode* node, std::vector<int> path, std::vector<int> &minPath){
    if (!node) return;
    path.push_back(node->value);
    if (!node->left && !node->right) {
        if (minPath.empty() || path < minPath) {
                minPath = path;
            }
        } else {
            FindPath(node->left, path, minPath);
            FindPath(node->right, path, minPath);
    }
}

std::vector<int> FindMinPath(TreeNode* node) {
    std::vector<int> minPath;
    std::vector<int> currentPath;
    FindPath(node, currentPath, minPath);
    return minPath;
}


void TestProcess(TreeNode* root) {
    std::vector<int> path = FindMinPath(root);

    if (!path.empty()) {
        std::cout << "Lexicographically smallest path: ";
        for (int i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No path (tree is empty)." << std::endl;
    }
}

TreeNode* BuildTree() {
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;

    if (n <= 0) return nullptr; 

    std::vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Enter value for node " << i << ": ";
        std::cin >> value;
        nodes[i] = new TreeNode(value);
    }

    std::cout << "Enter parent-child pairs (as parent_index child_index): " << std::endl;
    for (int i = 0; i < n - 1; ++i) {
        int parentIndex, childIndex;
        std::cin >> parentIndex >> childIndex;
        nodes[parentIndex]->left ? nodes[parentIndex]->right = nodes[childIndex] : nodes[parentIndex]->left = nodes[childIndex];
    }

    return nodes[0];
}

void DeleteTree(TreeNode* root) {
    if (!root) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = BuildTree();
    if (root) {
        TestProcess(root);
        DeleteTree(root);
    }
    return 0;
}

