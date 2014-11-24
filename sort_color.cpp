//


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
    void sortColors(int A[], int n) {
        //for (int i=0; i < n; i++) {
        //    cout << A[i] << " ";
        //}
        //cout << endl;
        qsort(A, 0, n-1);
        //for (int i=0; i < n; i++) {
        //    cout << A[i] << " ";
        //}
        //cout << endl;
    }

    void qsort(int A[], int low, int high) {
        if (low >= high) {
            return;
        }
        int first = low;
        int last = high;
        int key = A[first];
        while (first < last) {
            while(first < last && A[last] >= key) {
                last--;
            }
            A[first] = A[last];
            while (first < last && A[first] <= key) {
                first++;
            }
            A[last] = A[first];
        }
        A[first] = key;
        qsort(A, low, first-1);
        qsort(A, first+1, high);
    }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int in[4] = {2, 0, 1, 0};
    s.sortColors(in, 4);
    return 0;
}
