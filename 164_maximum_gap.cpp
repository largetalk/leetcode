/*
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

 Return 0 if the array contains less than 2 elements.

 Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
(3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.

*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        int maximumGap(vector<int>& nums) {
            if (nums.size() < 2) {
                return 0;
            }
            int res[nums.size()];
            int t[nums.size()][10];
            for (int i=0; i<nums.size(); i++) {
                res[i] = i;
                for (int j=0; j<10; j++) {
                    t[i][j] = 0;
                }
                int temp = nums[i], j = 9;
                while(temp) {
                    t[i][j--] = temp % 10;
                    temp /= 10;
                }
            }
            for (int i=9; i>=0; i--) {
                int bucket[nums.size()], count1[10];
                memset(count1, 0, sizeof(count1));
                for (int j=0; j<nums.size();j++) {
                    count1[t[res[j]][i]] ++;
                }
                for (int j=1; j <10; j++)
                    count1[j] += count1[j-1];
                for (int j=nums.size()-1;j>=0;j--) {
                    bucket[--count1[t[res[j]][i]]] = res[j];
                }
                for(int j = 0;j < nums.size();++j)
                    res[j] = bucket[j];
            }
            int ans =  INT_MIN;
            for(int i = 1;i < nums.size();++i)
                ans = max(ans,nums[res[i]] - nums[res[i - 1]]);
            return ans;

        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(3);
    words.push_back(6);
    words.push_back(9);
    words.push_back(1);
    int index = s.maximumGap(words);
    cout << index << '\n';
    return 0;
}
