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
using namespace std;

class Solution
{
    public:
        void dfs(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int> >& ans) {
            if (target < 0)
                return;
            if (target == 0) {
                ans.push_back(path);
                return;
            }
            for (int i=index; i<candidates.size(); i++) {
                path.push_back(candidates[i]);
                dfs(candidates, target-candidates[i], i, path, ans);
                path.pop_back();
            }
        }


        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > ans;
            vector<int> path;
            dfs(candidates, target, 0, path, ans);
            return ans;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int myints[] = {2,3,5};
    vector<int> candidates(myints, myints + sizeof(myints) / sizeof(int));
    int target = 8;
    vector<vector<int> > result = s.combinationSum(candidates, target);


    cout << "The contents of fifth are:\n";
    for (vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<int> ins = *it;
        for (vector<int>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }

    return 0;
}
