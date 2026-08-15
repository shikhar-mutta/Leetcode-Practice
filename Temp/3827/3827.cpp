// Link: https://leetcode.com/problems/count-monobit-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(n)). SC: O(1).
    // Use Binary representation of the number.
    // 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111.
    int countMonobit(int n)
    {
        int cnt = 0;
        int cur = 0;
        while (cur <= n)
        {
            ++cnt;
            cur = 2 * (cur + 1) - 1;
        }
        return cnt;
    }
};