//
//Determine whether an integer is a palindrome. Do this without extra space.


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            if (x < 10) {
                return true;
            }
            int base = 1;
            while (x /base >= 10) {
                base *= 10;
            }

            while (base) {
                int left = x /base;
                int right = x % 10;
                if (left != right) {
                    return false;
                } else {
                    x = x % base;
                    x = x / 10;
                    base = base / 100;
                }
            }
            return true;
        }
};



int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Solution s = Solution();
    cout << s.isPalindrome(9) << endl;
    cout << s.isPalindrome(121) << endl;
    cout << s.isPalindrome(13) << endl;
    cout << s.isPalindrome(1874994781) << endl;

    return 0;
}
