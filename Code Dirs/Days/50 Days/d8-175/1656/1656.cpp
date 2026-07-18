// Link: https://leetcode.com/problems/design-an-ordered-stream/description/

#include <bits/stdc++.h>
using namespace std;

class OrderedStream
{
    vector<string> arr;
    int ptr;

public:
    OrderedStream(int n) : arr(n + 1), ptr(1) {}

    vector<string> insert(int idKey, string value)
    {
        arr[idKey] = move(value); // move to avoid unnecessary copy
        int start = ptr;          // store the current pointer position
        while (ptr < (int)arr.size() && !arr[ptr].empty())
            ptr++;
        return {arr.begin() + start, arr.begin() + ptr}; // return the range of strings from the start position to the current pointer position
    }
};
