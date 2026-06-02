// Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int n = arr.size(), grt = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            int newGrt = max(grt, arr[i]);
            arr[i] = grt;
            grt = newGrt;
        }
        return arr;
    }
};
