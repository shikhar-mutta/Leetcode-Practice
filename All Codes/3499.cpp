// Link: https://leetcode.com/problems/maximize-active-section-with-trade-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach:
// 1. Count the number of '1's in the string, which represents the active sections.
// 2. Count the number of '0's in each contiguous segment of '0's and store them in an array B.
// 3. Iterate through the array B to find the maximum sum of two adjacent segments of '0's, which represents the maximum number of inactive sections that can be activated by trading with the active sections.
// 4. Return the sum of the count of '1's and the maximum sum of two adjacent segments of '0's.
constexpr int N = 1e5 + 1;
int B[N] = {0};
class Solution
{
public:
    static int maxActiveSectionsAfterTrade(string &s)
    {
        const int n = s.size();
        int cnt = 0, len = 0, j = 0;
        char prev = '@';
        for (char c : s)
        {
            cnt += c == '1';
            j += (prev != c && c == '0');
            B[j] += c == '0';
            prev = c;
        }
        int adj2 = 0;
        for (int i = 1; i < j; i++)
        {
            adj2 = max(adj2, B[i] + B[i + 1]);
        }
        // reset for the next testcase
        memset(B, 0, (j + 1) * sizeof(int));
        return cnt + adj2;
    }
};