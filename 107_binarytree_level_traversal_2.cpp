/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *        / \
 *          9  20
 *              /  \
 *                 15   7
 *                 return its bottom-up level order traversal as:
 *                 [
 *                   [15,7],
 *                     [9,20],
 *                       [3]
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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int> > ret;
            if(root != nullptr) {
                vector<TreeNode> v;
                v.push_back(*root);
                judge(v,ret);
            }
            return ret;

        }
        void judge(vector<TreeNode>& v,vector<vector<int> >& ret)
        {
            vector<TreeNode> v1;
            vector<int> v2;
            for(int i = 0;i < v.size();i++)
            {
                v2.push_back(v[i].val);
                if(v[i].left != nullptr)
                    v1.push_back(*(v[i].left));
                if(v[i].right != nullptr)
                    v1.push_back(*(v[i].right));
            }
            if(v1.size())
                judge(v1,ret);
            ret.push_back(v2);
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

    vector<vector<int> > result = s.levelOrderBottom(a);

    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }


    return 0;
}
