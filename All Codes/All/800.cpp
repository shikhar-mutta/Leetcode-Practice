// Link: https://leetcode.com/problems/similar-rgb-color/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: for each 2-hex-digit component, find the "shorthand" value (00,11,...,ff) minimizing squared difference by rounding value/17 to nearest integer (since shorthand values are k*17 for k=0..15).
class Solution {
    string closestPair(int val) {
        int k = round(val / 17.0);
        k = max(0, min(15, k));
        char c = k < 10 ? '0'+k : 'a'+(k-10);
        return string(2, c);
    }
public:
    string similarRGB(string color) {
        int r = stoi(color.substr(1,2), nullptr, 16);
        int g = stoi(color.substr(3,2), nullptr, 16);
        int b = stoi(color.substr(5,2), nullptr, 16);
        return "#" + closestPair(r) + closestPair(g) + closestPair(b);
    }
};
