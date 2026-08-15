// Link: https://leetcode.com/problems/find-the-key-of-the-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        auto pad = [](int x) {
            string s = to_string(x);
            while (s.size() < 4) s = "0" + s;
            return s;
        };
        string a = pad(num1), b = pad(num2), c = pad(num3);
        string res;
        for (int i = 0; i < 4; i++) {
            res += min({a[i], b[i], c[i]});
        }
        return stoi(res);
    }
};
