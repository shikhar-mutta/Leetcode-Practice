// Link: https://leetcode.com/problems/distribute-candies-among-children-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for (int a = 0; a <= min(n, limit); a++) {
            int rem = n - a;
            if (rem > 2 * limit) continue;
            int lo = max(0, rem - limit), hi = min(limit, rem);
            if (lo <= hi) cnt += hi - lo + 1;
        }
        return cnt;
    }
};
