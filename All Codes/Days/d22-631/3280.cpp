// Link: https://leetcode.com/problems/convert-date-to-binary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date) {
        // integer -> binary string (no leading zeros)
        auto toBin = [](int x) {
            string b;
            while (x) { b += char('0' + x % 2); x /= 2; }
            reverse(b.begin(), b.end());
            return b;
        };
        // date is "yyyy-mm-dd"; convert each field
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
        return toBin(y) + "-" + toBin(m) + "-" + toBin(d);
    }
};
