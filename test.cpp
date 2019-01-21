#include <string>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//double fast_exp(double y) {
//    double d;
//    *(reinterpret_cast<int*> (&d) + 0) = 0;
//    *(reinterpret_cast<int*> (&d) + 1) = static_cast<int> (1512775 * y + 1072632447);
//    return d;
//}
//
//int main(int argc, char* argv[]) {
//    vector<double> sims = {0.1,0.5, 0.9, 1, 1.5, 2.1, 5};
//    for (int i =0; i < sims.size(); i++) {
//        cout << sims[i] << ' ' << exp(sims[i]) << ' ' << fast_exp(sims[i]) << ' ' << exp(sqrt((int)(sims[i] * 10))) << '\n';
//    }
//    return 0;
//}


//bool myfunction (int i,int j) { return (i>j); }
//
//int main () {
//    std::vector<int> myvector;
//    const int nums(15);
//
//    // set some values:
//    for (int i=1; i<nums; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
//
//    std::random_shuffle (myvector.begin(), myvector.end());
//
//    // using default comparison (operator <):
//    std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end());
//
//    // using function as comp
//    //std::nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);
//
//    // print out content:
//    std::cout << "myvector contains:";
//    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
//        std::cout << ' ' << *it;
//    std::cout << '\n';
//
//    return 0;
//}
//


