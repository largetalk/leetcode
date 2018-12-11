/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
 *                 return its level order traversal as:
 *                 [
 *                   [3],
 *                     [9,20],
 *                       [15,7]
 *                       ]
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

        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int> > ans;
            if (root == NULL)
                return ans;
            vector<TreeNode*> level;
            level.push_back(root);
            while(!level.empty()) {
                vector<TreeNode*> tmp;
                vector<int> vals;
                for (int i=0; i < level.size(); i++) {
                    if (level[i]->left) {
                        tmp.push_back(level[i]->left);
                    }
                    if (level[i]->right) {
                        tmp.push_back(level[i]->right);
                    }
                    vals.push_back(level[i]->val);
                }
                ans.push_back(vals);
                level = tmp;
            }
            return ans;

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
    TreeNode* a =  new TreeNode(1);
    a->right = new TreeNode(2);
    a->right->left = new TreeNode(3);

    vector<vector<int> > result = s.levelOrder(a);

    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }


    return 0;
}
