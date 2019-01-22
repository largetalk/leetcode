/**
 * Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 *
 * Note:
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * Example 2:
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void dfs(int k, int n, int index, vector<int>& path, vector<vector<int> >& ans) {
            if (n<0 || k<0)
                return;
            if (n == 0 && k == 0) {
                ans.push_back(path);
                return;
            }
            for (int i=index; i<= 9; i++) {
                path.push_back(i);
                dfs(k-1, n-i, i+1, path, ans);
                path.pop_back();
            }
        }

            vector<vector<int>> combinationSum3(int k, int n) {
                vector<vector<int> > ans;
                vector<int> path;
                dfs(k, n, 1, path, ans);
                return ans;
                    
                }


};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<vector<int> > result = s.combinationSum3(3, 7);


    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
