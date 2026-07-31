// Link: https://leetcode.com/problems/longest-common-subpath/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * log(min(m))) SC: O(n * m)
// Approach: We can use binary search to find the length of the longest common subpath. For each length, we can use a rolling hash to check if there is a common subpath of that length among all paths. We can use two different bases and moduli to reduce the chance of hash collisions.
class Solution
{
    bool check(int L, const vector<vector<int>> &paths)
    {
        if (L == 0)
            return true;

        long long B1 = 100003, M1 = 1000000007;
        long long B2 = 100033, M2 = 998244353;

        long long p1 = 1, p2 = 1;
        for (int i = 0; i < L; ++i)
        {
            p1 = (p1 * B1) % M1;
            p2 = (p2 * B2) % M2;
        }

        vector<long long> valid_hashes;

        for (const auto &path : paths)
        {
            if ((int)path.size() < L)
                return false;

            vector<long long> current_hashes;
            current_hashes.reserve(path.size() - L + 1);
            long long h1 = 0, h2 = 0;

            for (int i = 0; i < L; ++i)
            {
                h1 = (h1 * B1 + path[i]) % M1;
                h2 = (h2 * B2 + path[i]) % M2;
            }
            current_hashes.push_back((h1 << 32) | h2);

            for (int i = L; i < (int)path.size(); ++i)
            {
                h1 = (h1 * B1 - path[i - L] * p1 % M1 + M1 + path[i]) % M1;
                h2 = (h2 * B2 - path[i - L] * p2 % M2 + M2 + path[i]) % M2;
                current_hashes.push_back((h1 << 32) | h2);
            }

            sort(current_hashes.begin(), current_hashes.end());
            current_hashes.erase(
                unique(current_hashes.begin(), current_hashes.end()),
                current_hashes.end());

            if (valid_hashes.empty())
            {
                valid_hashes = move(current_hashes);
            }
            else
            {
                vector<long long> next_valid;
                set_intersection(valid_hashes.begin(), valid_hashes.end(),
                                 current_hashes.begin(), current_hashes.end(),
                                 back_inserter(next_valid));
                valid_hashes = move(next_valid);
                if (valid_hashes.empty())
                    return false;
            }
        }
        return !valid_hashes.empty();
    }

public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        int min_len = paths[0].size();
        for (const auto &p : paths)
        {
            min_len = min(min_len, (int)p.size());
        }

        int left = 0, right = min_len;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(mid, paths))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};