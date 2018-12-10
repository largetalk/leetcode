/*
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * Note: You can only move either down or right at any point in time.
 *
 * Example:
 *
 * Input:
 * [
 *   [1,3,1],
 *     [1,5,1],
 *       [4,2,1]
 *       ]
 *       Output: 7
 *       Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int minPathSum(vector<vector<int> >& grid) {
            int n = grid.size();
            cout << "n: " << n << endl;
            if (!n) return 0;
            int m = grid[0].size();
            cout << "m: " << m << endl;
            int dp[n][m];
            dp[0][0] = grid[0][0];
            for (int i =1; i< m;i++) {
                dp[0][i] = dp[0][i-1] + grid[0][i];
            }
            for (int i = 1; i< n; i++) {
                dp[i][0] = dp[i-1][0] + grid[i][0];
            }
            for (int i=1; i< n; i++) {
                for (int j=1; j< m; j++) {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
            return dp[n-1][m-1];

        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> a = {1,2,5};
    vector<int> b = {3,2,1};
    //vector<int> c = {4,2,1};
    vector<vector<int> > grid = {a,b};
    int index = s.minPathSum(grid);
    cout << index << '\n';
    return 0;
}
