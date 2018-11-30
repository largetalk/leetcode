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
#include <map>
using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s) {
            map<int, int> m;
            int minOffset = 0;
            int maxL = 0;
            int curL = 0;
            for(int i=0; i<s.length(); i++) {
                if (m.find(s[i]) == m.end() || m[s[i]] < minOffset) {
                    curL++;
                } else {
                    minOffset = m[s[i]] + 1;
                    curL = i - m[s[i]];
                }
                m[s[i]] = i;
                if (curL > maxL) {
                    maxL = curL;
                }
            }
            return maxL;
        }

};

int main(int argc, char* argv[]){
    Solution s = Solution();
    cout << s.lengthOfLongestSubstring("abcabcbb") << '\n';
    cout << s.lengthOfLongestSubstring("bbbbbb") << '\n';
    cout << s.lengthOfLongestSubstring("pwwkew") << '\n';

    return 0;
}
