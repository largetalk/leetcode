//
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class MinStack {
    private:
        stack<int> v;
        stack<int> m;

    public:

        void push(int x) {
            if (m.empty() || x <= m.top()) {
                m.push(x);
            }
            v.push(x);
        }

        void pop() {
            if (v.top() == m.top()) {
                m.pop();
            }
            v.pop();
        }

        int top() {
            return v.top();
        }

        int getMin() {
            return m.top();
        }
};

int main(int argc, char* argv[]) {
    MinStack s = MinStack();
    for (int i = -10000; i < 10000; i++) {
        s.push(i);
    }
    cout << s.getMin() << endl;
    return 0;
}
