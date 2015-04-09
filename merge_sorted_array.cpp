//
//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {

    public:
        void merge(int A[], int m, int B[], int n) {
            int a = m -1;
            int b = n -1;
            int i = m +n -1;
            for (; i>0;i--) {
                if (A[a] > B[b]) {
                    A[i] = A[a--];
                } else {
                    A[i] = B[b--];
                }
                if (a < 0 || b < 0) {
                    break;
                }
            }
            if (b >= 0) {
                for ( ;b>=0;b--) {
                    A[b] = B[b];
                }
            }
        }
};

int main(int argc, char* argv[]) {
    cout << s.merge() << endl;
    return 0;
}
