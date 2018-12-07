/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 *
 * Example:
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int trap(vector<int>& height) {
            int l=0, sum1 = 0, water=0,i;
            for (i=1;i<height.size();i++) {
                if (height[i] >= height[l]) {
                    water += (i-l-1) * height[l] - sum1;
                    sum1 = 0;
                    l = i;
                } else {
                    sum1 += height[i];
                }
            }
            if (l != height.size()-1) {
                int temp = l;
                sum1 = 0;
                l = height.size()-1;
                for (i=l-1; i>=temp;--i) {
                    if (height[i] >= height[l]) {
                        water += (l-i-1) * height[l] - sum1;
                        sum1 = 0;
                        l = i;
                    } else {
                        sum1 += height[i];
                    }
                }
            }
            return water;
        }


};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(0);
    words.push_back(1);
    words.push_back(0);
    words.push_back(2);
    words.push_back(1);
    words.push_back(0);
    words.push_back(1);
    words.push_back(3);
    words.push_back(2);
    words.push_back(1);
    words.push_back(2);
    words.push_back(1);
    int index = s.trap(words);
    cout << index << '\n';
    return 0;
}
