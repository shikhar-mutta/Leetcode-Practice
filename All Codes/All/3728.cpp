// Link: https://leetcode.com/problems/stable-subarrays-with-equal-boundary-and-interior-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach:
// 1. We can use a prefix sum array to calculate the sum of elements in any subarray in O(1) time.
// 2. We can use a hash map to store the count of subarrays with a given boundary value and interior sum.
// 3. We can iterate through the array and for each element, we can check if there exists a subarray with the same boundary value and interior sum in the hash map.
// 4. If such a subarray exists, we can add its count to the answer.
class Solution
{
public:
    long long countStableSubarrays(vector<int> &capacity)
    {
        int n = capacity.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + capacity[i];

        struct Key
        {
            int val;
            long long pre;

            bool operator==(const Key &other) const
            {
                return val == other.val && pre == other.pre;
            }
        };

        struct Hash
        {
            size_t operator()(const Key &k) const
            {
                return hash<long long>()((k.pre << 1) ^ (long long)k.val);
            }
        };

        unordered_map<Key, int, Hash> cnt;
        long long ans = 0;

        for (int r = 0; r < n; r++)
        {
            if (r >= 2)
            {
                int l = r - 2;
                cnt[{capacity[l], pref[l]}]++;
            }

            Key need{capacity[r], pref[r] - 2LL * capacity[r]};
            auto it = cnt.find(need);
            if (it != cnt.end())
                ans += it->second;
        }

        return ans;
    }
};