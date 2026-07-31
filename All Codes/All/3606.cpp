// Link: https://leetcode.com/problems/coupon-code-validator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string,int> order = {{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};
        vector<pair<int,string>> valid;

        for (size_t i = 0; i < code.size(); i++) {
            if (code[i].empty()) continue;
            bool okCode = true;
            for (char c : code[i]) {
                if (!isalnum((unsigned char)c) && c != '_') { okCode = false; break; }
            }
            if (!okCode) continue;
            if (!order.count(businessLine[i])) continue;
            if (!isActive[i]) continue;
            valid.push_back({order[businessLine[i]], code[i]});
        }

        sort(valid.begin(), valid.end());
        vector<string> result;
        for (auto& [o, c] : valid) result.push_back(c);
        return result;
    }
};
