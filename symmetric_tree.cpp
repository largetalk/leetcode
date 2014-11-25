
#include <iostream>
#include <vector>
#include <stack>
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

// 中序遍历， wrong answer
//class Solution {
//public:
//    bool isSymmetric(TreeNode *root) {
//        if (root == NULL) {
//            return true;
//        }
//        vector<int> midV;
//        stack<TreeNode*> st;
//        TreeNode* t = root;
//        while(true) {
//            while(t != NULL) {
//                st.push(t);
//                t = t->left;
//            }
//            if (st.empty()) {
//                break;
//            }
//            t = st.top();
//            midV.push_back(t->val);
//            st.pop();
//            t = t->right;
//        }
//        int half = midV.size() / 2;
//        for (int i=0; i < half; i++) {
//            if (midV[i] != midV[midV.size() - i -1]) {
//                return false;
//            } 
//        }
//        return true;
//    }
//};
//
//

class Solution {

    public:
        bool isSymmetric(TreeNode *root) {
        }
};

int main(int args, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(2);
    root->left = left;
    root->right = right;
    Solution s;
    cout << s.isSymmetric(root) << endl;
    return 0;
}
