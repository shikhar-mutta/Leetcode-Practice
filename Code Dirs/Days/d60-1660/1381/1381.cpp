// Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for push and increment, O(n) for pop in worst case, SC: O(n)
// Approach:
//  1. We maintain two vectors, stk and inc, to store the elements of the stack and the increment values respectively. The stk vector is used to store the elements of the stack, while the inc vector is used to store the increment values for each element in the stack. The inc vector is initialized with zeros and has the same size as the stk vector.
//  2. The push function adds an element to the top of the stack if the stack size is less than the maximum size. It simply pushes the element onto the stk vector.
//  3. The pop function removes and returns the top element of the stack. It first checks if the stack is empty, and if so, returns -1. Otherwise, it retrieves the increment value for the top element from the inc vector, adds it to the top element, and then removes the top element from the stk vector. It also propagates the increment value to the next element in the stack by adding it to the inc value of the next element. Finally, it returns the incremented value of the popped element.
//  4. The increment function increments the bottom k elements of the stack by a given value. It calculates the index of the last element to be incremented (i) and adds the increment value to the inc vector at that index. This way, when the pop function is called, the increment value will be applied to the appropriate elements in the stack.
class CustomStack
{
    vector<int> stk, inc;
    int cap;

public:
    CustomStack(int maxSize) : cap(maxSize)
    {
        stk.reserve(maxSize);
        inc.assign(maxSize, 0);
    }
    void push(int x)
    {
        if (stk.size() < cap)
            stk.push_back(x);
    }
    int pop()
    {
        int i = stk.size() - 1;
        if (i < 0)
            return -1;
        int add = inc[i];
        inc[i] = 0;
        if (i > 0)
            inc[i - 1] += add;
        int res = stk.back() + add;
        stk.pop_back();
        return res;
    }
    void increment(int k, int val)
    {
        int i = min((int)stk.size(), k) - 1;
        if (i >= 0)
            inc[i] += val;
    }
};