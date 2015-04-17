//
//Given an integer n, return the number of trailing zeroes in n!.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
        int trailingZeroes(int n) {
            int ret = 0;
            while(n)
            {
                ret += n/5;
                n /= 5;
            }
            return ret;
        }
};



int main(int argc, const char * argv[]) {
    Solution s = Solution();
    cout << s.trailingZeroes(10) << endl;
}

