// Link: https://leetcode.com/problems/restore-ip-addresses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (at most 3^4 branches)  SC: O(1) extra (excluding output)
// Approach: backtracking, try 1-3 char segments at each of 4 positions, validating range and no leading-zero
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> parts;
        int n = s.size();
        function<void(int)> bt = [&](int start) {
            if (parts.size() == 4) {
                if (start == n) {
                    string ip = parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3];
                    res.push_back(ip);
                }
                return;
            }
            for (int len = 1; len <= 3 && start + len <= n; len++) {
                string seg = s.substr(start, len);
                if (seg.size() > 1 && seg[0] == '0') break;
                if (stoi(seg) > 255) break;
                parts.push_back(seg);
                bt(start + len);
                parts.pop_back();
            }
        };
        bt(0);
        return res;
    }
};
