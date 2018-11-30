/*
 *There are two sorted arrays nums1 and nums2 of size m and n respectively.

 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 You may assume nums1 and nums2 cannot be both empty.

 Example 1:

 nums1 = [1, 3]
 nums2 = [2]

 The median is 2.0
 Example 2:

 nums1 = [1, 2]
 nums2 = [3, 4]

 The median is (2 + 3)/2 = 2.5
 */


#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// solution 1
//class Solution {
//    public:
//        int getKth(vector<int> nums1, int start1, int end1, vector<int> nums2, int start2, int end2, int k) {
//            int len1 = end1 - start1 + 1;
//            int len2 = end2 - start2 + 1;
//            if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
//            if (len1 == 0) return nums2[start2 + k - 1];
//
//            if (k == 1) return min(nums1[start1], nums2[start2]);
//
//            int i = start1 + min(len1, k / 2) - 1;
//            int j = start2 + min(len2, k / 2) - 1;
//
//            if (nums1[i] > nums2[j]) {
//                return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
//            }
//            else {
//                return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
//            }
//        }
//        double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
//            int n = nums1.size();
//            int m = nums2.size();
//            int left = (n + m + 1) / 2;
//            int right = (n + m + 2) / 2;
//            return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
//        }
//};

//solution 2
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size(),n = nums2.size(),sum = m + n;
            if(!nums1.size())
                return sum % 2 ? nums2[sum / 2] : (nums2[sum /2] + nums2[sum / 2 - 1]) / 2.0;
            if(!nums2.size())
                return sum % 2 ? nums1[sum / 2] : (nums1[sum /2] + nums1[sum / 2 - 1]) / 2.0;
            if(m > n)
                return findMedianSortedArrays(nums2,nums1);
            int l = 0,r = m - 1;
            while(l < r)
            {
                int mid = (l + r) / 2;
                int j = (sum + 1) / 2 - mid - 2;
                int min1 = max(nums1[mid],nums2[j]),max1 = min(nums1[mid + 1],nums2[j + 1]);
                if(min1 <= max1)
                    return sum % 2 ? min1 : (min1 + max1) / 2.0;
                else if(nums1[mid] > nums2[j])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            int j = (sum + 1) / 2 - l - 2;
            int min1,max1;
            if(j < 0)
                min1 = nums1[l];
            else
                min1 = max(nums1[l],nums2[j]);
            if(l == nums1.size() - 1)
                max1 = nums2[j + 1];
            else
                max1 = min(nums1[l + 1],nums2[j + 1]);
            if(min1 <= max1)
                return sum % 2 ? min1 : (min1 + max1) / 2.0;
            j++;
            if(j < nums2.size() - 1)
                max1 = min(nums1[l],nums2[j + 1]);
            else
                max1 = nums1[l];
            min1 = nums2[j];
            return sum % 2 ? min1 : (min1 + max1) / 2.0;
        }
};


int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> num1;
    num1.push_back(1);
    num1.push_back(2);

    vector<int> num2;
    num2.push_back(3);
    num2.push_back(4);

    cout << s.findMedianSortedArrays(num1, num2) << '\n';
}

