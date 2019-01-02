/**
 * Given an input string, reverse the string word by word.

Example:

Input: "the sky is blue",
Output: "blue is sky the".
Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
Follow up: For C programmers, try to solve it in-place in O(1) space.
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
        void reverseWords(string &s) {
            int i = 0,j = s.length();
            while(i < j && s[i] == ' ')
                i++;
            j--;
            while(j >= i && s[j] == ' ')
                j--;
            j++;
            string s1;
            while(j >= i)
            {
                int temp = j - 1;
                while(temp >= 0 && s[temp] != ' ')
                    temp--;
                int t = temp;
                temp++;
                while(j > temp)
                    s1.push_back(s[temp++]);
                j = t - 1;
                while(j >= i && s[j] == ' ')
                    j--;
                j++;
                if(j >= i)
                    s1.push_back(' ');
            }
            s = s1;
        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    string str = "the sky is blue";
    s.reverseWords(str);
    cout << str << '\n';

    return 0;
}
