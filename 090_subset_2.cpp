/**
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *     [1],
 *       [1,2,2],
 *         [2,2],
 *           [1,2],
 *             []
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
        void dfs(vector<int>& nums, int index, vector<int> subset, vector<vector<int> >& ans) {
            ans.push_back(subset);
            if (index == nums.size())
                return;

            for (int i=index; i < nums.size(); i++) {
                if (i> index && nums[i-1] == nums[i])
                    continue;
                subset.push_back(nums[i]);
                dfs(nums, i+1, subset, ans);
                subset.pop_back();
            }

        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int> > ans;
            vector<int> subset;
            sort(nums.begin(), nums.end());
            dfs(nums, 0, subset, ans);
            return ans;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<int> nums = {1, 2, 2};
    vector<vector<int> > result = s.subsetsWithDup(nums);


    cout << "The contents of fifth are:\n";
    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
