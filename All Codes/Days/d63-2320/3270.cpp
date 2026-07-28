// Link: https://leetcode.com/problems/find-the-key-of-the-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(1)
// Approach: Zero-pad each number to 4 digits, then take the digit-wise
// minimum at each of the 4 positions (comparing as chars works since digit
// ordering matches char ordering) to build the key.
class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string a = to_string(num1);
        string b = to_string(num2);
        string c = to_string(num3);

        while (a.size() < 4)
            a = '0' + a;
        while (b.size() < 4)
            b = '0' + b;
        while (c.size() < 4)
            c = '0' + c;

        string res;
        for (int i = 0; i < 4; i++) {
            res += char(min({a[i], b[i], c[i]}));
        }

        return stoi(res);
    }
};
