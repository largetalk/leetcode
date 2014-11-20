//
//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct  Node {
    int num, pos;
};

bool cmp(Node a, Node b) {
    return a.num < b.num;
}

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            vector<int> result;
            vector<Node> array;
            for (int i=0; i < numbers.size(); i++) {
                Node temp;
                temp.num = numbers[i];
                temp.pos = i + 1;
                array.push_back(temp);
            }
            sort(array.begin(), array.end(), cmp);
            for (int i=0, j = array.size() - 1; i != j;) {
                int sum = array[i].num + array[j].num;
                if (sum == target) {
                    if (array[i].pos < array[j].pos) {
                        result.push_back(array[i].pos);
                        result.push_back(array[j].pos);
                    } else {
                        result.push_back(array[j].pos);
                        result.push_back(array[i].pos);
                    }
                    break;
                } else {
                    if (sum < target) {
                        i++;
                    } else {
                        j--;
                    }
                }
            }
            return result;
        }

};



int main(int argc, const char * argv[]) {
    Solution s = Solution();
    vector<int> in;
    in.push_back(2);
    in.push_back(7);
    in.push_back(11);
    in.push_back(15);
    vector<int> out = s.twoSum(in, 9);
    for (int i=0; i < out.size(); i++) {
        cout << out[i] << " ";
    }
    cout << endl;
}

