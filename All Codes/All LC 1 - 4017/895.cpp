// Link: https://leetcode.com/problems/maximum-frequency-stack/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(n)
// Approach: maintain a map from frequency to stack of values with that frequency,
// and a map from value to its frequency. Push: increment frequency, push onto
// corresponding stack, update max frequency. Pop: pop from max frequency stack,
// decrement frequency, if stack is empty decrement max frequency.
// Note: this is a classic problem that can be solved with a clever use of data structures.
class FreqStack
{
    unordered_map<int, stack<int>> fstack; // key : freq,, val :stack
    int maxcount = 0;
    unordered_map<int, int> freq; // key : num, val : freq
public:
    FreqStack() {}

    void push(int val)
    {
        freq[val]++;
        maxcount = max(maxcount, freq[val]);
        fstack[freq[val]].push(val);
    }

    int pop()
    {
        int temp = fstack[maxcount].top();
        fstack[maxcount].pop();
        freq[temp]--;

        if (fstack[maxcount].empty())
        {
            maxcount--;
        }

        return temp;
    }
};
