/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
            int numTrees(int n) {
                int dp[n+1];
                dp[0] = 1;
                dp[1] = 1;
                for (int i=2; i<=n; i++) {
                    dp[i] = 0;
                }
                for (int i=2; i<=n; i++) {
                    for (int j=0; j<i; j++) {
                        dp[i] += dp[i-j-1] * dp[j];
                    }
                }
                return dp[n];

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
    int result = s.numTrees(3);

    cout << result << '\n';

    return 0;
}
