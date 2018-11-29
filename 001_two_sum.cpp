/**
  给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

  candidates 中的数字可以无限制重复被选取。

  说明：

  所有数字（包括 target）都是正整数。
  解集不能包含重复的组合。 
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> m;
            vector<int> res;
            for (int i = 0; i < nums.size(); ++i) {
                m[nums[i]] = i;
            }
            for (int i = 0; i < nums.size(); ++i) {
                int t = target - nums[i];
                if (m.count(t) && m[t] != i) {
                    res.push_back(i);
                    res.push_back(m[t]);
                    break;
                }
            }
            return res;
        }


};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int myints[] = {2,7, 11, 15};
    vector<int> candidates(myints, myints + sizeof(myints) / sizeof(int));
    int target = 9;
    vector<int> result = s.twoSum(candidates, target);


    cout << "The contents of fifth are:\n";
    for (vector<int>::iterator itn = result.begin(); itn != result.end(); ++ itn)
        cout << ' ' << *itn;

    cout << '\n';

    return 0;
}
