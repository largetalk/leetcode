/*
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
    public:

        int threeSumClosest(vector<int>& nums, int target) {
            int ans = 999999;
            int minGap = 99999;
            sort(nums.begin(),nums.end());
            for(int i = 0;i < nums.size();++i)
            {
                int t1 = i + 1,t2 = nums.size() - 1;
                while(t1 < t2) {
                    int sum = nums[i] + nums[t1] + nums[t2];
                    int gap = sum - target;
                    if (gap == 0)
                        return target;
                    cout << nums[i] << ' ' << nums[t1] << ' ' << nums[t2] << ' ' << sum << ' ' << gap << endl;
                    if (abs(gap) < minGap) {
                        minGap = abs(gap);
                        ans = sum;
                    }
                    if(gap < 0) {
                            ++t1;
                    } else {
                            --t2;
                    }
                }
            }
            return ans;
        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> height;
    height.push_back(-1);
    height.push_back(2);
    height.push_back(1);
    height.push_back(-4);

    int target = 1;

    cout << s.threeSumClosest(height, target) << endl;

    //int a[] = {1,2,4,8,16,32,64,128};
    //vector<int> nums(a, a+8);
    //int target = 82;
    //cout << s.threeSumClosest(nums, target) << endl;

}

