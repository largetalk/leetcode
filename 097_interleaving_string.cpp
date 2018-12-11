/*
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 *
 * Example 1:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * Example 2:
 *
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 */

#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        bool isInterleave(string s1, string s2, string s3) {
            int l1 = s1.length(),l2 = s2.length(),l3 = s3.length();
            if(l1 + l2 != s3.length())
                return 0;
            int dp[l1 + 2][l2 + 2];
            memset(dp,0,sizeof(dp));
            dp[l1][l2] = 1;
            for(int i = l1;i >= 0;--i)
                for(int j = l2;j >= 0;--j)
                {
                    if(i < l1 && s1[i] == s3[i + j] && dp[i + 1][j])
                        dp[i][j] = 1;
                    if(j < l2 && s2[j] == s3[i + j] && dp[i][j + 1])
                        dp[i][j] = 1;
                }
            return dp[0][0];
        }


};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << s.isInterleave("a", "", "c") << endl;
    cout << s.isInterleave("aabc", "abad", "aabadabc") << endl;
    return 0;
}
