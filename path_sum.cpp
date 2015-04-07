//Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

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
        bool hasPathSum(TreeNode *root, int sum) {
            if (root != NULL) {
               if (root->left == NULL && root->right == NULL && root->val == sum) {
                   return true;
               } 
               return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum- root->val);
            }
            return false;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    TreeNode root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(3);
    root.left = &left;
    root.right = &right;
    cout << s.hasPathSum(&root, 4) << endl;
    return 0;
}
