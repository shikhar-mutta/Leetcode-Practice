// Link: https://leetcode.com/problems/additive-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n)
// Approach: try every split of first two numbers, then verify the rest of
// the string matches successive sums (string addition to avoid overflow)
class Solution {
    string addStrings(const string& a, const string& b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += char('0' + sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool check(const string& num, int i, int j, int k) {
        // segments: [0,i), [i,j), [j,k) as first two numbers then continue
        string a = num.substr(0, i);
        string b = num.substr(i, j - i);
        if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0')) return false;
        int pos = j;
        while (pos < (int)num.size()) {
            string c = addStrings(a, b);
            if (num.compare(pos, c.size(), c) != 0) return false;
            pos += c.size();
            a = b;
            b = c;
        }
        return pos == (int)num.size();
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(num, i, j, n)) return true;
            }
        }
        return false;
    }
};
