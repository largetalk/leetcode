/**
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 *
 * Example:
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 *   [2,4],
 *     [3,4],
 *       [2,3],
 *         [1,2],
 *           [1,3],
 *             [1,4],
 *             ]
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void dfs(vector<vector<int> >& ans, vector<int>& path, int n, int index, int k) {
            if (k==0) {
                ans.push_back(path);
                return;
            }
            for (int i = index; i <= n; i++) {
                path.push_back(i);
                dfs(ans, path, n, i+1, k-1);
                path.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> path;
            dfs(ans, path, n, 1, k);
            return ans;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<vector<int> > result = s.combine(4, 2);


    cout << "The contents of fifth are:\n";
    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
