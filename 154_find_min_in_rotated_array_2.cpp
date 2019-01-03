/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * The array may contain duplicates.
 *
 * Example 1:
 *
 * Input: [1,3,5]
 * Output: 1
 * Example 2:
 *
 * Input: [2,2,2,0,1]
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
            while(i < j && nums[i] >= nums[j]) {
                int mid = (i+j) /2;
                if (nums[mid] == nums[i]) 
                    i++;
                else if (nums[mid] > nums[i]) {
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
    words.push_back(1);
    words.push_back(3);
    //words.push_back(0);
    //words.push_back(1);
    int index = s.findMin(words);
    cout << index << '\n';
    return 0;
}
