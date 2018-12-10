/*
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true, otherwise return false.
 *
 * Example 1:
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * Example 2:
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        bool searchInternal( const vector<int>& Nums, const int Target, int Left, int Right ) {
            if (Right <= Left) return false;
            while(Left < Right -1) {
                int mid = (Left + Right) / 2;
                if (Nums[Left] == Nums[mid]) {
                    return searchInternal(Nums, Target, Left, mid) || searchInternal(Nums, Target, mid, Right);
                }
                if (Target < Nums[mid]) {
                    if (Nums[Left] < Nums[mid] && Nums[Left] > Target) {
                        Left = mid;
                    } else {
                        Right = mid;
                    }
                } else if (Target > Nums[mid]) {
                    if (Nums[Left] > Nums[mid] && Nums[Left] <= Target) {
                        Right = mid;
                    } else {
                        Left = mid;
                    }
                } else {
                    return true;
                }
            }
            return Nums[Left] == Target;
        }


        bool search(vector<int>& nums, int target) {
            return searchInternal(nums,target,0,nums.size());
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words = {2,5,6,0,0,1,2};
    int target = 3;
    int index = s.search(words, target);
    cout << index << '\n';
    return 0;
}
