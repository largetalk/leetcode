/*
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int jump(vector<int>& nums) {
            int i=0, next = nums[0], ans=0;
            int length = nums.size();
            if (length < 2)
                return 0;
            while(i<length) {
                ++ans;
                if (next >= length-1) {
                    return ans;
                }
                int cur = i;
                for (int j=cur+1;j <= min(next, length-1); ++j) {
                    i = max(i, nums[j] + j);
                }
                swap(i, next);
            }
        }


};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(2);
    words.push_back(3);
    words.push_back(1);
    words.push_back(1);
    words.push_back(4);
    int index = s.jump(words);
    cout << index << '\n';
    return 0;
}
