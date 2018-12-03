/*
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters like . or *.
 *
 * Example 1:
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 * Example 2:
 *
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 *
 * Example 3:
 *
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 * Example 4:
 *
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
 *
 * Example 5:
 *
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 */


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
        bool isMatch_(string s,string p,int i,int j){
            //cout << s << ' ' << p << ' ' << i << ' ' << j << '\n';
            if(i==-1&&j==-1){
                return 1;
            }else if(i!=-1&&j==-1){
                return 0;
            }else if(i==-1&&j!=-1){
                while(p[j]=='*'&&j>=0){
                    j-=2;
                }
                if(j==-1){
                    return 1;
                }else{
                    return 0;
                }
            }else{
                if(p[j]=='*'){
                    //cout << s << ' ' << p << ' ' << i << ' ' << j << '\n';
                    if (j==0) {
                        return 1;
                    }
                    if(p[j-1]=='.'||p[j-1]==s[i]){
                        if(isMatch_(s,p,i-1,j)){
                            return 1;
                        }
                        return isMatch_(s,p,i,j-2);
                    }else{
                        return isMatch_(s,p,i,j-2);
                    }
                }else if(p[j]=='.'||p[j]==s[i]){
                    return isMatch_(s,p,i-1,j-1);
                }else{
                    return 0;
                }
            }
        }
        bool isMatch(string s, string p) {
            int len_s=s.length(),len_p=p.length();
            return isMatch_(s,p,len_s-1,len_p-1);

        }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();

    cout << s.isMatch("abcd", "*") << '\n';
    cout << s.isMatch("abcd", "abcd*") << '\n';
    cout << s.isMatch("abcd", "abc*") << '\n';
    cout << s.isMatch("abc", "abcd*") << '\n';
}

