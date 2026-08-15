// Link: https://leetcode.com/problems/maximum-swap/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(d) SC: O(d)
// Approach: for each digit position, find the rightmost larger digit later in the number and swap with the leftmost occurrence of that larger digit found so far (track last occurrence index of each digit 0-9).
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) last[s[i]-'0'] = i;
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > s[i]-'0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};
