/*
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
*/


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            if (nums.size() < 4) return vector<vector<int>>{};
            set<vector<int>> res;
            sort(nums.begin(), nums.end());
            for (size_t i = 0; i < nums.size() - 3; ++i)
                for (size_t j = i + 1; j < nums.size() - 2; ++j) {
                    auto left_idx = j + 1; auto right_idx = nums.size() - 1;
                    int sum = 0;
                    for (left_idx = j + 1, right_idx = nums.size() - 1; left_idx < right_idx; sum > target ? --right_idx : ++left_idx) {
                        sum = nums[i] + nums[j] + nums[left_idx] + nums[right_idx];
                        if (sum == target) {
                            vector<int> res_single{nums[i], nums[j], nums[left_idx], nums[right_idx]};
                            res.insert(res_single);
                        }

                    }
                }
            return vector<vector<int>>(res.begin(), res.end());
        }
};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> height;
    height.push_back(1);
    height.push_back(0);
    height.push_back(-1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(-2);

    vector<vector<int> > result = s.fourSum(height, 0);


    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

}

