// Link: https://leetcode.com/problems/elimination-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: track head, remaining count, and step; head moves forward
// only when eliminating from the left, or (right-elimination with odd remaining count)
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1, remaining = n;
        bool leftToRight = true;
        while (remaining > 1) {
            if (leftToRight || remaining % 2 == 1) head += step;
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return head;
    }
};
