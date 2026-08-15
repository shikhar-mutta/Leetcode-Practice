// Link: https://leetcode.com/problems/count-symmetric-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int x = low; x <= high; x++) {
            string s = to_string(x);
            if (s.size() % 2 != 0) continue;
            int half = s.size() / 2;
            int sum1 = 0, sum2 = 0;
            for (int i = 0; i < half; i++) sum1 += s[i] - '0';
            for (int i = half; i < (int)s.size(); i++) sum2 += s[i] - '0';
            if (sum1 == sum2) cnt++;
        }
        return cnt;
    }
};
