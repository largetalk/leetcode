/*
 * Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
    public:
            vector<vector<int>> threeSum(vector<int>& nums) {
   vector<vector<int> > ret;
    sort(nums.begin(),nums.end());
    for(int i = 0;i < nums.size();++i)
    {
        int t1 = i + 1,t2 = nums.size() - 1;
        if(i && nums[i] == nums[i - 1])
            continue;
        while(t1 < t2)
            if(nums[t1] + nums[t2] == -nums[i])
            {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[t1]);
                v.push_back(nums[t2]);
                ret.push_back(v);
                ++t1;
                --t2;
            }
            else if(nums[t1] + nums[t2] < -nums[i])
                ++t1;
            else
                --t2;
    }
    auto pos = unique(ret.begin(),ret.end());
    ret.erase(pos,ret.end());
    return ret;
    }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> height;
    height.push_back(-1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(2);
    height.push_back(-1);
    height.push_back(-4);

        vector<vector<int> > result = s.threeSum(height);


    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

}

