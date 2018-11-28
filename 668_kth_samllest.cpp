/**
  Nearly every one have used the Multiplication Table. But could you find out the k-th smallest number quickly from the multiplication table?

  Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k-th smallest number in this table.
 **/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{

    public:
        bool enough(int x, int m, int n, int k) {
            int count = 0;
            for (int i = 1; i <= m; i++) {
                int c = x / i;
                if (c <= n) {
                    count += c;
                } else {
                    count += n;
                }
            }
            return count >= k;
        }

        int findKthNumber(int m, int n, int k) {
            int lo = 1, hi = m * n;
            while (lo < hi) {
                int mi = lo + (hi - lo) / 2;
                if (!enough(mi, m, n, k)) lo = mi + 1;
                else hi = mi;
            }
            return lo;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int result = s.findKthNumber(2, 3, 6);


    cout << "The contents of fifth are: " << result;
    cout << '\n';

    return 0;
}
