// Link: https://leetcode.com/problems/largest-multiple-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        int sum = 0;
        for (int d : digits) sum += d;
        int mod = sum % 3;

        if (mod != 0) {
            bool removed = false;
            for (int i = 0; i < (int)digits.size(); i++) {
                if (digits[i] % 3 == mod) {
                    digits.erase(digits.begin() + i);
                    removed = true;
                    break;
                }
            }
            if (!removed) {
                int need = 3 - mod;
                int count = 0;
                for (int i = 0; i < (int)digits.size() && count < 2; ) {
                    if (digits[i] % 3 == need) {
                        digits.erase(digits.begin() + i);
                        count++;
                    } else i++;
                }
            }
        }

        sort(digits.rbegin(), digits.rend());
        if (digits.empty()) return "";
        if (digits[0] == 0) return "0";

        string res;
        for (int d : digits) res += char('0' + d);
        return res;
    }
};
