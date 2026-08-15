// Link: https://leetcode.com/problems/count-distinct-numbers-on-board/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1 ? 1 : n - 1;
    }
};
