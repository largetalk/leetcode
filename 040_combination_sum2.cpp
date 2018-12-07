/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * Example 1:
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 *   [1, 7],
 *     [1, 2, 5],
 *       [2, 6],
 *         [1, 1, 6]
 *         ]
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int> >& ans) {
            if (target < 0)
                return;
            if (target == 0) {
                ans.push_back(path);
                return;
            }
            for (int i=index; i<candidates.size(); i++) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                path.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i+1, path, ans);
                path.pop_back();
            }
        }


        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > ans;
            vector<int> path;
            dfs(candidates, target, 0, path, ans);
            return ans;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int myints[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(myints, myints + sizeof(myints) / sizeof(int));
    int target = 8;
    vector<vector<int> > result = s.combinationSum(candidates, target);


    cout << "The contents of fifth are:\n";
    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
