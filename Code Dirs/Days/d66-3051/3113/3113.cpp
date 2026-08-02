// Link: https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: maintain a monotonic (non-increasing) stack of (value, count)
// pairs, where count = number of subarrays ending here whose max equals
// value and both boundary elements equal that max. Pop entries smaller
// than the current num (they can no longer be a boundary max going
// right). If the top now equals num, increment its count (extends the
// matching-boundary group) and add that count to the answer; otherwise
// push a fresh (num, 1) and add 1 (the single-element subarray).
class Solution
{
public:
    long long numberOfSubarrays(vector<int> &nums)
    {
        vector<pair<int, long long>> st;
        long long ans = 0;
        for (int num : nums)
        {
            while (!st.empty() && st.back().first < num)
                st.pop_back();
            if (!st.empty() && st.back().first == num)
            {
                st.back().second++;
                ans += st.back().second;
            }
            else
            {
                st.push_back({num, 1});
                ans += 1;
            }
        }
        return ans;
    }
};
