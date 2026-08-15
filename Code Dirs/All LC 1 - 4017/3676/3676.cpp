// Link: https://leetcode.com/problems/count-bowl-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: For each element, check if there is a greater element on the left and right side of it. If yes, then it is a bowl subarray. We can find the next greater element on the right side using a single pass from right to left and storing the maximum value seen so far. For the left side, we can keep track of the maximum value seen so far while iterating from left to right.
class Solution
{
public:
    long long bowlSubarrays(vector<int> &a)
    {
        int n = a.size();
        vector<int> nxt(n, -1);
        nxt[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            nxt[i] = max(a[i], nxt[i + 1]);
        }
        int c = 0;
        int lmax = a[0];
        for (int i = 1; i < n - 1; i++)
        {
            // cout<<lmax<<" "<<a[i]<<" "<<nxt[i]<<endl;
            if (lmax > a[i] and nxt[i] > a[i])
                c++;
            lmax = max(lmax, a[i]);
        }
        return c;
    }
};