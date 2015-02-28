//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//

#include <iostream>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            int *A = new int[n+1];
            for (int i = 0; i < n+1; i++) {
                A[i] = -1;
            }
            int count = inner(A, n);
            delete[] A;
            return count;
        }

        int inner(int A[], int i) {
            if (i < 2) {
                return 1;
            }
            if (A[i] != -1) {
                return A[i];
            }
            int count = inner(A, i-1) + inner(A, i-2);
            A[i] = count;
            return count;
        }
};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    cout << s.climbStairs(6) << endl;
    cout << s.climbStairs(44) << endl;
}
