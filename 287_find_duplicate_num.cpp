/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 * Example 2:
 *
 * Input: [3,1,3,4,2]
 * Output: 3
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

        int toBitRow(int n) {
            return (n-1) / 32;
        }

        int toBitCol(int n) {
            int s = ((n-1) % 32);
            return 1 << s;
        }
        int findDuplicate(vector<int>& nums) {
            int bm[1000] = {0};
            for (int i=0; i<nums.size();i++) {
                int r = toBitRow(nums[i]);
                int c = toBitCol(nums[i]);
                cout << nums[i] << ' ' << r << ' ' << c << ' ' << bm[r] << endl;
                if (bm[r] & c) {
                    return nums[i];
                }
                bm[r] |= c;
            }
        }


        //int findDuplicate(vector<int>& nums) {
        //    for(int i=0;i<nums.size();i++){
        //            int index = abs(nums[i])-1;
        //            if(nums[index]<0)
        //                return index+1;
        //            nums[index] = - nums[index];
        //        }
        //}

        void printArr(int m[]) {
            for (int i=0; i < 32; i++) {
                cout << m[i] << ' ';
            }
            cout << '\n';
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<int> a = {2,2,2,2};
    int result= s.findDuplicate(a);
    cout << result << '\n';



    return 0;
}
