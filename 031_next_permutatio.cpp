/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        void nextPermutation(vector<int>& nums) {
            int n1 = 0,n2 = 0;
            for(int i = 1;i < nums.size();++i) {
                cout << n1 << ' ' << n2 << ' ' << i << endl;
                if(nums[i] > nums[n2])
                {
                    n1 = n2;
                    n2 = i;
                }
                else if((nums[i] < nums[n2] && nums[i] > nums[n1]) || nums[i] == nums[n2])
                    n2 = i;
                else if(nums[i] <= nums[n1])
                {
                    int j = i;
                    for(;j < nums.size() - 1;++j)
                        if(nums[j + 1] > nums[j])
                        {
                            n1 = j;
                            n2 = j + 1;
                            break;
                        }
                    i = j + 1;
                }
            }
            cout << n1 << ' ' << n2 <<  endl;
            if(n1 == n2)
                sort(nums.begin(),nums.end());
            else
            {
                swap(nums[n1],nums[n2]);
                sort(nums.begin() + n1 + 1,nums.end());
            }
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> words;
    words.push_back(2);
    words.push_back(4);
    words.push_back(6);
    words.push_back(5);
    words.push_back(3);
    s.nextPermutation(words);
    for (int i=0; i < words.size(); i++) {
        cout << ' ' << words[i];
    }
    cout << '\n';
    return 0;
}
