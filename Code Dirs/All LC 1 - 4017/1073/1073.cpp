// Link: https://leetcode.com/problems/adding-two-negabinary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> res;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += arr1[i--];
            if (j >= 0) sum += arr2[j--];
            res.push_back(((sum % 2) + 2) % 2);
            carry = -(sum >> 1);
            if (sum < 0 && sum % 2 != 0) carry = -((sum - 1) / 2);
        }
        while (res.size() > 1 && res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
