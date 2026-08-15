// Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: A pair sums to a multiple of 24 iff their remainders mod 24 sum
// to 0 or 24. Track a count of remainders seen so far; for each new hour,
// add the count of the complementary remainder (24 - r, or 0 if r is 0)
// before adding this hour's own remainder to the map.
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        long long ans = 0;
        vector<int> mp(24, 0);
        mp[hours[0] % 24]++;
        for (int i = 1; i < n; i++) {
            if (hours[i] % 24 == 0) {
                ans += mp[0];
            } else {
                ans += mp[24 - (hours[i] % 24)];
            }
            mp[hours[i] % 24]++;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
