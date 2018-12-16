/**
 * Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:

As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
Example 2:

Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
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
            int numDistinct(string s, string t) {
                int l1 = s.length(), l2 = t.length();
                int dp[l1+1][l2+1];
                memset(dp, 0, sizeof(dp));
                for (int i=1; i <= l1; i++)
                    if (s[i-1] == t[0])
                        dp[i][1] = 1;
                //printDP(*dp, l1, l2);
                for (int i=1; i <= l1; i++) {
                    for (int j=1; j <= l2; j++) {
                        if (s[i-1] != t[j-1])
                            dp[i][j] = dp[i-1][j];
                        else
                            dp[i][j] += (dp[i-1][j-1] + dp[i-1][j]);
                    }
                    for (int k=0; k < i; k++) {
                        cout << s[k];
                    }
                    cout << ' ' << t << '\n';
                    printDP(*dp, l1, l2);
                }
                return dp[l1][l2];
    }
            void printDP(int* dp, int l1, int l2) {
                for (int i=0; i <= l1; i++) {
                    for (int j=0; j <= l2; j++) {
                        cout << ' ' << *(dp + i*(l2+1) + j);
                    }
                    cout << '\n';
                }
                cout << "################\n";
            }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    cout << "rabbbit" << ' ' << "rabbit" << '\n';
    cout << s.numDistinct("rabbbit", "rabbit") << '\n';

    return 0;
}
