/**
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 *
 * For example, given the following triangle
 *
 * [
 *      [2],
 *          [3,4],
 *             [6,5,7],
 *               [4,1,8,3]
 *               ]
 *               The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 *
 *               Note:
 *
 *               Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
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
        int minimumTotal(vector<vector<int>>& triangle) {
            for (int i= triangle.size() -2; i >=0; i--)
                for (int j = 0; j< triangle[i].size();j++) {
                    triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
                }
            return triangle[0][0];
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<vector<int>> triangle;
    vector<int> a1 = {2};
    vector<int> a2 = {3,4};
    vector<int> a3 = {6,5,7};
    vector<int> a4 = {4,1,8,3};
    triangle.push_back(a1);
    triangle.push_back(a2);
    triangle.push_back(a3);
    triangle.push_back(a4);
    cout << s.minimumTotal(triangle) << '\n';

    return 0;
}
