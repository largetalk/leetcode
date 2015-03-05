//
//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {

    public:
    void rotate(int nums[], int n, int k) {
        k = k%n;
        k = n-k;
        for (int i=k-1; i>=0; i--) {
            int tmp = nums[i];
            int j = i;
            for (; j < n+i-k; j++) {
                nums[j] = nums[j+1];
            }
            nums[j] = tmp;
        }
    }
};

int main(int argc, char* argv[]){
    Solution s = Solution();
    int nums[] = {1,2,3,4,5,6,7};
    s.rotate(nums, 7, 3);
    for (int i=0;i<7;i++) {
        cout << nums[i];
    }
    cout << endl;


    int num1[] = {1,2};
    s.rotate(num1, 2, 3);
    for (int i=0;i<2;i++) {
        cout << num1[i];
    }
    cout << endl;


    int num2[] = {1,2,3};
    s.rotate(num2, 3, 1);
    for (int i=0;i<3;i++) {
        cout << num2[i];
    }
    cout << endl;
    return 0;
}
