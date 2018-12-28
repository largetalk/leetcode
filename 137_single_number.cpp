/**
 * Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * Example 1:
 *
 * Input: [2,2,3,2]
 * Output: 3
 * Example 2:
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
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
        int singleNumber(vector<int>& nums) {
            int m[32] = {0};
            for (int k=0; k<nums.size(); k++) {
                int x = nums[k];
                for (int i=0; i<32;i++) {
                    if (x & 1) {
                        m[i] ++;
                    }
                    x = x>>1;
                }
            }
            printArr(m);

            int y=0;
            for (int i=31; i>=0; i--) {
                y = y << 1;
                if (m[i]%3) {
                    y += 1;
                }
            }
            return y;

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
    vector<int> a = {0,1,0,1,0,1,99};
    int result= s.singleNumber(a);
    cout << result << '\n';



    return 0;
}
