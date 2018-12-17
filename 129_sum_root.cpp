/**
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 *
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 *
 * Find the total sum of all root-to-leaf numbers.
 *
 * Note: A leaf is a node with no children.
 *
 * Example:
 *
 * Input: [1,2,3]
 *     1
 *        / \
 *          2   3
 *          Output: 25
 *          Explanation:
 *          The root-to-leaf path 1->2 represents the number 12.
 *          The root-to-leaf path 1->3 represents the number 13.
 *          Therefore, sum = 12 + 13 = 25.
 *          Example 2:
 *
 *          Input: [4,9,0,5,1]
 *              4
 *                 / \
 *                   9   0
 *                    / \
 *                    5   1
 *                    Output: 1026
 *                    Explanation:
 *                    The root-to-leaf path 4->9->5 represents the number 495.
 *                    The root-to-leaf path 4->9->1 represents the number 491.
 *                    The root-to-leaf path 4->0 represents the number 40.
 *                    Therefore, sum = 495 + 491 + 40 = 1026.
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    public:
        void dfs(TreeNode* root, string path, int& sum) {
            if (root == NULL)
                return;
            if (root->left==NULL && root->right==NULL) {
                //path = path+std::to_string(root->val);
                int tmp = std::stoi(path);
                sum += (tmp * 10 + root->val);
                return;
            }
            dfs(root->left, path+ std::to_string(root->val), sum);
            dfs(root->right, path + std::to_string(root->val), sum);
        }

        int sumNumbers(TreeNode* root) {
            int sum = 0;
            dfs(root, "0", sum);
            return sum;
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.sumNumbers(root) << '\n';
    cout << std::stoi("0") << '\n';

    return 0;
}
