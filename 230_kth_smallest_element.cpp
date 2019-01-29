/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Example 1:
 *
 * Input: root = [3,1,4,null,2], k = 1
 *    3
 *      / \
 *       1   4
 *         \
 *            2
 *            Output: 1
 *            Example 2:
 *
 *            Input: root = [5,3,6,2,4,null,null,1], k = 3
 *                   5
 *                         / \
 *                              3   6
 *                                  / \
 *                                     2   4
 *                                       /
 *                                        1
 *                                        Output: 3'
 **/

#include <stdio.h>
#include <iostream>
#include <algorithm>
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
        void dfs(TreeNode* root, vector<int>& nums){
            if(root==NULL)
                return ;
            nums.push_back(root->val);
            dfs(root->left, nums);
            dfs(root->right, nums);
        }
        int kthSmallest(TreeNode* root, int k) {
            vector<int> nums;
            dfs(root, nums);
            sort(nums.begin(), nums.end());
            return  nums[k-1];
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    int ret = s.kthSmallest(root, 1);
    cout << ret << '\n';

    return 0;
}
