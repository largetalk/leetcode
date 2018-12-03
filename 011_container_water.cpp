/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 */


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:
            int maxArea(vector<int>& height) {
        int i = 0,j = height.size() - 1,ans = INT_MIN;
		while(i < j)
		{
			int t = min(height[i],height[j]);
			ans = max(ans,t * (j - i));
			height[i] < height[j] ? i++ : j--;
		}
		return ans;
    }

};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);

    cout << s.maxArea(height) << '\n';

}

