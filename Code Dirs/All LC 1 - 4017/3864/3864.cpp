// Link: https://leetcode.com/problems/minimum-cost-to-partition-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
//  Approach: We can use a divide-and-conquer approach to find the minimum cost to partition a binary string. We first calculate the prefix sum of the binary string to get the number of 1's in any substring. Then, we use a recursive function to calculate the minimum cost for each substring. The cost of encoding a substring is calculated based on the number of 1's in the substring and the encoding cost. If the length of the substring is even, we can split it into two equal halves and calculate the minimum cost for each half. The final result is obtained by taking the minimum of the cost of encoding the entire substring and the sum of the costs of encoding the two halves. We repeat this process for all possible substrings and return the minimum cost.
int cnts[100001], enc, flat;

long long eval(int l, int r)
{
    int n = cnts[r] - cnts[l];
    if (n == 0)
        return flat;

    int sz = r - l;
    long long score = (long long)sz * n * enc;
    if (sz & 1)
        return score;

    int m = (l + r) / 2;
    return min(score, eval(l, m) + eval(m, r));
}

class Solution
{
public:
    long long minCost(string s, int encCost, int flatCost)
    {
        int N = size(s);
        for (int i = 0; i < N; ++i)
            cnts[i + 1] = cnts[i] + s[i] - '0';
        enc = encCost;
        flat = flatCost;
        return eval(0, N);
    }
};
