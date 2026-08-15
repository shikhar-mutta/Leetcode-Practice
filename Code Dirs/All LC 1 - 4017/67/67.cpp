// Link: https://leetcode.com/problems/add-binary/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(max(n,m))  SC: O(max(n,m))
// Approach: simulate binary addition from the least significant bit, carrying as needed
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (char)('0' + sum % 2);
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
