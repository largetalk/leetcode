/*
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 * Example 1:
 *
 * Input:
 *   s = "barfoothefoobarman",
 *     words = ["foo","bar"]
 *     Output: [0,9]
 *     Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
 *     The output order does not matter, returning [9,0] is fine too.
 *     Example 2:
 *
 *     Input:
 *       s = "wordgoodstudentgoodword",
 *         words = ["word","student"]
 *         Output: []
 */

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {

    public:
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> ans;
            if(!s.length() || !words.size())
                return ans;
            unordered_map<string,int> m1;
            int len = words.size(),wl = words[0].length(),sl = s.length();
            for(int i = 0;i < words.size();++i)
                m1[words[i]]++;
            int left = 0;
            for(int i = 0;i < sl - wl * len + 1;++i)
            {
                unordered_map<string,int> m2;
                for(int j=0,left = i;j < len;j ++)
                {
                    string temp = s.substr(left,wl);
                    left += wl;
                    m2[temp]++;
                }
                if(m2 == m1)
                    ans.push_back(i);
            }
            return ans;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    vector<int> result = s.findSubstring("barfoothefoobarman", words);
    for (int i=0; i < result.size(); i++) {
        cout << ' ' << result[i] << '\n';
    }
    return 0;
}
