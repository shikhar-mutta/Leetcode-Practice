// Link: https://leetcode.com/problems/find-the-sum-of-encrypted-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int total = 0;
        for (int x : nums) {
            int mx = 0;
            int t = x;
            while (t) { mx = max(mx, t % 10); t /= 10; }
            int len = to_string(x).size();
            int enc = 0;
            for (int i = 0; i < len; i++) enc = enc * 10 + mx;
            total += enc;
        }
        return total;
    }
};
