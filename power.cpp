//
//implement pow(x,n)
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        double pow(double x, long long n) {
            if (n==0) {
                return 1.0;
            }
            if (n < 0) {
                return 1.0/pow(x, -n);
            }
            double half = pow(x, n>>1);
            if (n%2==0) {
                return half*half;
            } else {
                return half*half*x;
            }
        }
};

int main(int argc, char* argv[]) {
    Solution s = Solution();
    cout << s.pow(1.5, 2) << endl;
    cout << s.pow(1.5, 4) << endl;
    cout << s.pow(1.5, 8) << endl;
    cout << s.pow(1.5, 16) << endl;
    cout << s.pow(1.5, 65) << endl;
    cout << s.pow(0.00001, 2147483647) << endl;
    cout << s.pow(1.0, -2147483648UL) << endl;
    return 0;
}
