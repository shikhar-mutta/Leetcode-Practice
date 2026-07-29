// Link: https://leetcode.com/problems/sum-of-total-strength-of-wizards/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: We can use a monotonic stack to solve this problem. We can iterate through the strength array and maintain a stack of indices of the elements in the array. For each element, we can pop elements from the stack until we find an element that is less than or equal to the current element. We can then calculate the contribution of the popped elements to the total strength and add it to the answer. Finally, we can return the answer modulo 10^9 + 7.
class Solution
{
public:
    int totalStrength(vector<int> &strength)
    {
        static constexpr int64_t mod{1000000007};
        const auto n{strength.size()};
        array<int64_t, 100001> st;
        array<int64_t, 100001> pref;
        array<int64_t, 100001> pp;
        size_t top{0};
        pref[0] = pp[0] = 0;
        for (size_t i{0}; i < n; ++i)
        {
            pp[i + 1] = (pp[i] + (pref[i + 1] = pref[i] + strength[i])) % mod;
        }
        st[top] = -1;
        int64_t ans{0};
        for (int64_t i{0}; i < n; ++i)
        {
            const auto v{strength[i]};
            while (top && strength[st[top]] >= v)
            {
                const auto j{st[top]};
                const auto k{st[--top]};
                const auto l{((i - j) * (pp[j] - (top ? pp[k] : 0) + mod)) %
                             mod};
                const auto r{((j - k) * (pp[i] - pp[j] + mod)) % mod};
                ans = (ans + (r - l + mod) * strength[j]) % mod;
            }
            st[++top] = i;
        }
        while (top)
        {
            const auto i{st[top]};
            const auto k{st[--top]};
            const auto l{((n - i) * (pp[i] - (top ? pp[k] : 0) + mod)) % mod};
            const auto r{((i - k) * (pp[n] - pp[i] + mod)) % mod};
            ans = (ans + (r - l + mod) * strength[i]) % mod;
        }
        return ans;
    }
};
