/*
 * Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {

    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string> > ans;
            map<string, vector<string> > maps;
            for (int i=0; i < strs.size(); i++) {
                string tmp = strs[i];
                sort(tmp.begin(), tmp.end());
                maps[tmp].push_back(strs[i]);
            }
            for (auto item:maps) {
                ans.push_back(item.second);
            }
            return ans;

        }

};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    vector<string> words;
    words.push_back("eat");
    words.push_back("tea");
    words.push_back("tan");
    words.push_back("ate");
    words.push_back("nat");
    words.push_back("bat");
    vector<vector<string> > result= s.groupAnagrams(words);

    cout << "The contents of fifth are:\n";
    for (vector<vector<string> >::iterator it = result.begin(); it != result.end(); ++it) {
        vector<string> ins = *it;
        for (vector<string>::iterator itn = ins.begin(); itn != ins.end(); ++ itn)
            cout << ' ' << *itn;

        cout << '\n';
    }
    return 0;
}
