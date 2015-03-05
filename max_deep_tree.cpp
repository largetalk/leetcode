//
//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

    public:
        int maxDepth(TreeNode *root) {
            if (root == NULL) {
                return 0;
            }
            return 1+ max(maxDepth(root->left), maxDepth(root->right));
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    TreeNode root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(3);
    cout << s.maxDepth(&root) << endl;
    root.left = &left;
    root.right = &right;
    cout << s.maxDepth(&root) << endl;
    return 0;
}
