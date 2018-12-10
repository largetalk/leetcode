/**
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *     [1],
 *       [2],
 *         [1,2,3],
 *           [1,3],
 *             [2,3],
 *               [1,2],
 *                 []
 *                 ]
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
            vector<vector<int>> subsets(vector<int>& nums) {
                vector<vector<int> > ans;
                for (int i =0; i< pow(2, nums.size()); i++) {
                    vector<int> tmp;
                    int j = i;
                    int index = 0;
                    while(j) {
                        if (j%2 == 1) {
                            tmp.push_back(nums[index]);
                        }
                        index++;
                        j/=2;
                    }
                    ans.push_back(tmp);
                }
                return ans;
                    
                }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int> > result = s.subsets(nums);


    cout << "The contents of fifth are:\n";
    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
