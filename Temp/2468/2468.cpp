// Link: https://leetcode.com/problems/split-message-based-on-limit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        int b = 0;
        long long capacity = 0;
        for (b = 1; b <= n; b++) {
            string bStr = to_string(b);
            long long suffixLenSum = 0;
            bool ok = true;
            for (int i = 1; i <= b; i++) {
                string suffix = "<" + to_string(i) + "/" + bStr + ">";
                if ((int)suffix.size() >= limit) { ok = false; break; }
                suffixLenSum += suffix.size();
            }
            if (!ok) continue;
            capacity = (long long)limit * b - suffixLenSum;
            if (capacity >= n) break;
        }
        if (b > n) return {};

        vector<string> result;
        string bStr = to_string(b);
        int pos = 0;
        for (int i = 1; i <= b; i++) {
            string suffix = "<" + to_string(i) + "/" + bStr + ">";
            int avail = limit - (int)suffix.size();
            int take = min(avail, n - pos);
            result.push_back(message.substr(pos, take) + suffix);
            pos += take;
        }
        return result;
    }
};
