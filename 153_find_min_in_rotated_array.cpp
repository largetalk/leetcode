/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 * Input: [3,4,5,1,2] 
 * Output: 1
 * Example 2:
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int findMin(vector<int>& nums) {
            int i = 0,j = nums.size() - 1;
            while(nums[i] > nums[j]) {
                int mid = (i+j) >>1;
                if (nums[mid] >= nums[i]) {
                    i = mid+1;
                } else {
                    j = mid;
                }
            }
            return nums[i];
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(3);
    words.push_back(4);
    words.push_back(5);
    words.push_back(1);
    words.push_back(2);
    int index = s.findMin(words);
    cout << index << '\n';
    return 0;
}
