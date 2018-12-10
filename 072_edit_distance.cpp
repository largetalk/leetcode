/*
 Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

 You have the following 3 operations permitted on a word:

 Insert a character
 Delete a character
 Replace a character
 Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 */

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        vector<vector<int> > dp;

        int minLen(string& w1, string& w2, int i, int j ) {
            if (i < 0)
                return j + 1;
            if (j < 0)
                return i + 1;
            if (dp[i][j])
                return dp[i][j];
            if (w1[i] == w2[j]) {
                dp[i][j] = minLen(w1, w2, i-1, j-1);
                return dp[i][j];
            }
            int temp = min(minLen(w1, w2, i-1, j) + 1, minLen(w1, w2, i-1, j-1) + 1);
            dp[i][j] = min(minLen(w1, w2, i, j-1) + 1, temp);
            return dp[i][j];
        }

           int minDistance(string word1, string word2) {
               int i = word1.length() -1, j = word2.length() -1;
               for (int t1 = 0; t1 <= i; t1++) {
                   vector<int> v1;
                   for (int t2=0; t2 <= j; t2++) {
                       v1.push_back(0);
                   }
                   dp.push_back(v1);
               }
               int m = minLen(word1, word2, i, j);
               return m;
                   
               }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int result = s.minDistance("horse", "ros");
    cout << ' ' << result << '\n';
    return 0;
}
