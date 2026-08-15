// Link: https://leetcode.com/problems/friends-of-appropriate-ages/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1), where n is the length of ages.
    // Approach: Count the number of people of each age and then for each age, count the number of friend requests that can be sent to other ages based on the given conditions.
    int numFriendRequests(vector<int> &ages)
    {
        vector<long long> cnt(121, 0);
        for (int a : ages)
            cnt[a]++;

        long long res = 0;
        for (int a = 1; a <= 120; a++)
        {
            if (cnt[a] == 0)
                continue;
            for (int b = a / 2 + 8; b <= a; b++)
            {
                if (cnt[b] == 0)
                    continue;
                res += cnt[a] * (b == a ? cnt[a] - 1 : cnt[b]);
            }
        }
        return (int)res;
    }
};
