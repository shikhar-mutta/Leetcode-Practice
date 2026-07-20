// Link: https://leetcode.com/problems/longest-square-streak-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n*sqrt(max(nums))) ~ O(nlogn) + O(n*317) ~ O(nlogn)
    // SC: O(n)
    //  Approach:
    //  1. Create a bitset of size 100001 to mark the presence of numbers in the input array.
    //  2. Iterate through the numbers from 2 to 316 (since 317^2 > 100000) and check if the number is present
    //     in the bitset.
    //  3. If the number is present, initialize a counter and a variable to keep track of the current number. Then, repeatedly square the current number and check if the squared value is present in the bitset. If it is, increment the counter and update the current number to the squared value. Continue this process until the squared value exceeds 100000 or is not present in the bitset.
    //  4. Keep track of the maximum counter value found during the iterations.
    //  5. If the maximum counter value is greater than 1, return it; otherwise, return -1.

    int longestSquareStreak(vector<int> &nums)
    {
        bitset<100001> bt;
        int cnt = 0, ans = 0;
        long long v = 0;
        for (int &x : nums)
            bt[x] = 1;
        for (int i = 2; i < 317; i++)
            if (bt[i] == 1)
            {
                cnt = 1;
                v = i;
                bt[i] = 0;
                while ((v * v < 100001) && (bt[v * v] == 1))
                    cnt++, v *= v, bt[i] = 0;
                ans = max(ans, cnt);
            }
        return (ans > 1) ? ans : -1;
    }
};