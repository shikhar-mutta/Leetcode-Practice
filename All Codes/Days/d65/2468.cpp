// Link: https://leetcode.com/problems/split-message-based-on-limit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N * digits), SC: O(N)
// Approach: try total part count b from 1 upward; suffix "<i/b>" length depends on digit counts.
// Find smallest b where every part has capacity>=1 and total capacity across parts >= message
// length, then greedily fill parts front-to-back with as many message chars as each fits.
class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size();
        for (long long b = 1; b <= n; b++) {
            string bStr = to_string(b);
            long long sumSuffix = 0;
            bool feasible = true;
            for (long long i = 1; i <= b; i++) {
                long long suffixLen = (long long)to_string(i).size() + bStr.size() + 3;
                if (suffixLen >= limit) { feasible = false; break; }
                sumSuffix += suffixLen;
            }
            if (!feasible) continue;
            if (b * (long long)limit - sumSuffix < n) continue;

            vector<string> ans;
            int pos = 0;
            for (long long i = 1; i <= b; i++) {
                string suffix = "<" + to_string(i) + "/" + bStr + ">";
                int cap = limit - (int)suffix.size();
                int take = min((int)(n - pos), cap);
                ans.push_back(message.substr(pos, take) + suffix);
                pos += take;
            }
            return ans;
        }
        return {};
    }
};
