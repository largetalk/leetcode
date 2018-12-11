/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * Return the following binary tree:
 *
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if (postorder.empty() || inorder.empty())
                return NULL;
            TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
            if (postorder.size() ==1) {
                return root;
            }
            vector<int> inorder_left;
            vector<int> inorder_right;
            bool flag = false;
            for (int i =0; i<inorder.size();i++)
                if (inorder[i] == root->val) {
                    flag = true;
                } else if (flag) {
                    inorder_right.push_back(inorder[i]);
                } else {
                    inorder_left.push_back(inorder[i]);
                }

            vector<int> postorder_left;
            vector<int> postorder_right;
            for (int i=0; i<inorder_left.size(); i++)
                postorder_left.push_back(postorder[i]);
            for (int i=0; i<inorder_right.size(); i++)
                postorder_right.push_back(postorder[i + postorder_left.size() ]);
            root->left = buildTree(inorder_left, postorder_left);
            root->right = buildTree(inorder_right, postorder_right);
            return root;
        }




        void printNodes(TreeNode* root) {
            if (root != NULL) {
                cout << root->val << endl;
                printNodes(root->left);
                printNodes(root->right);
            }
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<int> in = {9,3,15,20,7};
    vector<int> post = {9,15,7,20,3};

    TreeNode* root = s.buildTree(in, post);
    s.printNodes(root);



    return 0;
}
