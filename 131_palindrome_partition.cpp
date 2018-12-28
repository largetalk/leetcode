/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 *
 * Return all possible palindrome partitioning of s.
 *
 * Example:
 *
 * Input: "aab"
 * Output:
 * [
 *   ["aa","b"],
 *     ["a","a","b"]
 *     ]
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
        bool isValid(string str){
            for(int i=0;i<str.length()/2;i++){
                if(str[i]!=str[str.length()-i-1])
                    return false;
            }
            return true;
        }

        void dfs(int start, vector<string>& path, vector<vector<string>>& ans, string s){
            if(start == s.length()){
                ans.push_back(path);
                return ;
            }
            for(int i=start;i<s.length();i++){
                if(isValid(s.substr(start, i-start+1))){
                    path.push_back(s.substr(start, i-start+1));
                    dfs(i+1, path, ans, s);
                    path.pop_back();
                }
            }

        }

        vector<vector<string>> partition(string s) {
            vector<vector<string>> ans;
            if(s.length()==0)
                return ans;
            vector<string> path;
            dfs(0, path, ans, s);
            return ans;

        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<vector<string>> result= s.partition("aab");

    for (vector<vector<string> >::iterator it = result.begin(); it != result.end(); ++it) {
            vector<string> ins = *it;
            for (vector<string>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
                cout << ' ' << *itn;
    
            cout << '\n';
    }


    return 0;
}
