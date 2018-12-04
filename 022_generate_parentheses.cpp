/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 */


#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class Solution {
    public:
        void dfs(int left, int total, string path, vector<string>& ans){
            //cout << "# " << left << ' ' << total << ' ' << path << endl;
            if(total==0&&left==0){
                ans.push_back(path);
                return ;
            }
            if(left>0)
                dfs(left-1, total-1, path+"(", ans);
            if(left<total-left)
                dfs(left, total-1, path+")", ans);
        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            string path="";
            dfs(n, n*2, path, ans);
            return ans;
        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<string>  result = s.generateParenthesis(3);

    for (vector<string>::iterator itn = result.begin(); itn != result.end(); ++ itn)
        cout <<  *itn << endl;
}

