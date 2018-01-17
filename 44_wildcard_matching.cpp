/**
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
**/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   bool isMatch(const char *s, const char *p)
   {
        const char *ss = s, *pp = NULL;
        while('\0' != *s)
        {
             if('?' == *p || *s == *p)
                 ++ s, ++ p;
             else if('*' == *p)
                 ss = s, pp = p ++;
             else if(pp != NULL)
                 s = ++ ss, p = pp + 1;
             else
                 return false;
         }

        while('*' == *p)
            ++ p;

        return '\0' == *p;
    }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    count << s.isMatch("aa", "a") <<endl;


    return 0;
}
