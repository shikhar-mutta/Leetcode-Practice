// Link: https://leetcode.com/problems/next-closest-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) bounded (try all 1440 minutes) SC: O(1)
// Approach: collect the allowed digit set from the input time; brute-force scan every minute forward from current+1 (wrapping at 1440), and return the first time whose HH:MM digits are all within the allowed set.
class Solution {
public:
    string nextClosestTime(string time) {
        set<char> digits;
        for (char c : time) if (isdigit(c)) digits.insert(c);
        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));
        int cur = h*60 + m;
        for (int add = 1; add <= 1440; add++) {
            int t = (cur + add) % 1440;
            int nh = t / 60, nm = t % 60;
            char buf[6];
            snprintf(buf, sizeof(buf), "%02d%02d", nh, nm);
            bool ok = true;
            for (char c : string(buf)) if (!digits.count(c)) { ok = false; break; }
            if (ok) {
                string res;
                res += buf[0]; res += buf[1]; res += ':'; res += buf[2]; res += buf[3];
                return res;
            }
        }
        return time;
    }
};
