//Given a non-negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int size = digits.size();
            for (int i = size - 1; i >= 0; i--) {
                int data = digits[i] + 1;
                if (data < 10) {
                    digits[i] = data;
                    break;
                } else {
                    digits[i] = 0;
                }
            }
            if (digits[0] == 0) {
                vector<int>::iterator it = digits.begin();
                digits.insert(it, 1);
            }
            return digits;
        }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    vector<int> dig1;
    dig1.push_back(9);
    dig1.push_back(9);
    vector<int> ret1 = s.plusOne(dig1);
    for (int i = 0; i < ret1.size(); i++) {
        cout << ret1[i];
    }
    cout << endl;
    return 0;
}
