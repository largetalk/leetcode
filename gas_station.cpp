
//There are N gas stations along a circular route, 
//where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of 
//gas to travel from station i to its next station (i+1).
//You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index
//if you can travel around the circuit once, otherwise return -1.'

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            int start = 0;
            int size = gas.size();
            while(start < size) {
                int remain = 0;
                int i = 0;
                for (;i < size;i++) {
                    int cur = (start + i) % size;
                    remain = remain + gas[cur] - cost[cur];
                    if (remain < 0) {
                        break;
                    }
                }
                if (remain >= 0) {
                    return start;
                } else {
                    start = start + i + 1;
                }
            }
            return -1;
        }
};

int main(int argc, char* argv[]){
    cout << "hello world" << endl;
    Solution s = Solution();
    vector<int> gas1;
    vector<int> cost1;
    gas1.push_back(4);
    cost1.push_back(5);
    cout << s.canCompleteCircuit(gas1, cost1) << endl;

    vector<int> gas2;
    vector<int> cost2;
    gas2.push_back(2);
    gas2.push_back(4);
    cost2.push_back(3);
    cost2.push_back(4);
    cout << s.canCompleteCircuit(gas2, cost2) << endl;

    vector<int> gas3;
    vector<int> cost3;
    gas3.push_back(1);
    gas3.push_back(2);
    gas3.push_back(3);
    gas3.push_back(3);
    cost3.push_back(2);
    cost3.push_back(1);
    cost3.push_back(5);
    cost3.push_back(1);
    cout << s.canCompleteCircuit(gas3, cost3) << endl;
    return 0;
}
