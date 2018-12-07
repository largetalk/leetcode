/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1'
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int search(vector<int>& nums, int target) {
            int i = 0,j = nums.size() - 1;
            if(!nums.size())
                return -1;
            while(i < j - 1)
            {
                int mid = (i + j) / 2;
                if(nums[i] < nums[mid])
                    i = mid;
                else
                    j = mid;
            }
            if(nums[i] <= nums[j])
                j = i;
            auto pos = lower_bound(nums.begin(),nums.begin() + j,target);
            if(pos != nums.end() && (*pos) == target)
                return pos - nums.begin();
            pos = lower_bound(nums.begin() + j,nums.end(),target);
            if(pos != nums.end() && (*pos) == target)
                return pos - nums.begin();
            return -1;
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(1);
    words.push_back(2);
    words.push_back(3);
    words.push_back(4);
    words.push_back(5);
    words.push_back(6);
    int target = 4;
    int index = s.search(words, target);
    cout << index << '\n';
    return 0;
}
