// Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while ((int)s.size() > k) {
            string next;
            for (int i = 0; i < (int)s.size(); i += k) {
                string group = s.substr(i, k);
                int sum = 0;
                for (char c : group) sum += c - '0';
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};
