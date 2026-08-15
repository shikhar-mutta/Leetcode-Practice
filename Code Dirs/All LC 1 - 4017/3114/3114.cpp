// Link: https://leetcode.com/problems/latest-time-you-can-obtain-after-replacing-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        for (int hh = 11; hh >= 0; hh--) {
            for (int mm = 59; mm >= 0; mm--) {
                char buf[6];
                snprintf(buf, sizeof(buf), "%02d:%02d", hh, mm);
                bool ok = true;
                for (int i = 0; i < 5; i++) {
                    if (s[i] != '?' && s[i] != buf[i]) { ok = false; break; }
                }
                if (ok) return string(buf);
            }
        }
        return "";
    }
};
