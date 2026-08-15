// Link: https://leetcode.com/problems/lexicographical-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra
// Approach: simulate lexicographic traversal - go deeper (x*10) if within
// range, else advance to sibling (x+1), backtracking past trailing 9s
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res.push_back(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur + 1 > n) cur /= 10;
                cur++;
            }
        }
        return res;
    }
};
