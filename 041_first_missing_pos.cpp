/*
 * Given an unsorted integer array, find the smallest missing positive integer.
 *
 * Example 1:
 *
 * Input: [1,2,0]
 * Output: 3
 * Example 2:
 *
 * Input: [3,4,-1,1]
 * Output: 2
 * Example 3:
 *
 * Input: [7,8,9,11,12]
 * Output: 1
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int firstMissingPositive(vector<int>& nums) {
            if(!nums.size())
                return 1;
            for(int i = 0;i < nums.size();)
            {
                if(nums[i] < nums.size() && nums[i] != nums[nums[i] - 1])
                    swap(nums[i],nums[nums[i] - 1]);
                else
                    ++i;
            }
            for(int i = 0;i < nums.size();++i)
                if(nums[i] != i + 1)
                    return i + 1;
            return nums.size() + 1;
        }


};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(7);
    words.push_back(8);
    words.push_back(9);
    words.push_back(11);
    words.push_back(12);
    int index = s.firstMissingPositive(words);
    cout << index << '\n';
    return 0;
}
