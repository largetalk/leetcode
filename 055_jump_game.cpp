/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
            bool canJump(vector<int>& nums) {
                if (nums.size() <=1)
                    return 1;
                for (int i=0, r=0; i < nums.size()-1;) {
                    int max1 = 0;
                    while (i <= r) {
                        max1 = max(max1, i + nums[i]);
                        ++i;
                    }
                    if (max1 >= nums.size() -1) {
                        return 1;
                    }
                    if (max1 <= r) {
                        return 0;
                    }
                    r = max1;
                }

    }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    //words.push_back(2);
    //words.push_back(2);
    //words.push_back(1);
    //words.push_back(1);
    words.push_back(0);
    bool index = s.canJump(words);
    cout << index << '\n';
    return 0;
}
