/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
 *
 * Example:
 *
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * Note:
 *
 * The order of the result is not important. So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    public:
        vector<int> singleNumber(vector<int>& nums) {
            int aXorB = 0;
            for (int num : nums) {
                aXorB ^= num;
            }
            int differingBit = 1;
            while ((differingBit & aXorB) == 0) {
                differingBit <<= 1;
            }
            int a = 0;
            int b = 0;
            for (int num : nums) {
                if ((num & differingBit) == 0) {
                    a ^= num;
                } else {
                    b ^= num;
                }
            }
            return {a, b};
        }

        void printArr(int m[]) {
            for (int i=0; i < 32; i++) {
                cout << m[i] << ' ';
            }
            cout << '\n';
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> a = {0,1,0,3,1,99};
    vector<int> result= s.singleNumber(a);
    cout << result[0] << ' ' << result[1] << '\n';



    return 0;
}
