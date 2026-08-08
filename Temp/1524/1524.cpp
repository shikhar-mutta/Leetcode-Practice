// Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        long long odd = 0, even = 1, sum = 0, result = 0;
        for (int x : arr) {
            sum += x;
            if (sum % 2 == 0) {
                result = (result + odd) % MOD;
                even++;
            } else {
                result = (result + even) % MOD;
                odd++;
            }
        }
        return (int)result;
    }
};
