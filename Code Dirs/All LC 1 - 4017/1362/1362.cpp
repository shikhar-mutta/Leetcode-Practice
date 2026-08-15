// Link: https://leetcode.com/problems/closest-divisors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPair(int n) {
        for (int a = (int)sqrt(n); a >= 1; a--) {
            if (n % a == 0) return {a, n / a};
        }
        return {1, n};
    }

    vector<int> closestDivisors(int num) {
        vector<int> p1 = findPair(num + 1);
        vector<int> p2 = findPair(num + 2);
        if (abs(p1[1] - p1[0]) <= abs(p2[1] - p2[0])) return p1;
        return p2;
    }
};
