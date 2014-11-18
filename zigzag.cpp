//
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
    string convert(string s, int nRows) {
        int block = 0;
        if (nRows <= 2) {
            block = nRows;
        } else {
            block = 2 * nRows - 2;
        } 

        char* out = new char[s.length() + 1];
        out[s.length()] = '\0';
        int jnum = s.length() / block;
        if (s.length() % block) {
            jnum++;
        }
        int k = 0;
        for (int i = 0; i < nRows; i++) {
            for (int j=0; j < jnum; j++) {
                if ( j * block + i < s.length() ){
                    out[k++] = s[j*block + i];
                }
                if (nRows > 2 && i != 0 && i != nRows-1) {
                    if (j* block + block - i < s.length()) {
                        out[k++] = s [ j* block + block - i];
                    }
                }
            }
        }
        return out;
    }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("AB", 1) << endl;
    return 0;
}
