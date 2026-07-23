// Link: https://leetcode.com/problems/circular-permutation-in-binary-representation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        int size = 1 << n; // 2^n total numbers
        vector<int> result(size);
        for (int i = 0; i < size; i++)
        {
            result[i] = start ^ (i ^ (i >> 1));
        }
        return result;
    }
};