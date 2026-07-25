// Link: https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: Alice wins iff x+y is odd, i.e. one of x,y is odd and the other
// even. Count odd/even values in [1,n] and [1,m] separately, then the total
// is (odd-x choices * even-y choices) + (even-x choices * odd-y choices).
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddX = (n + 1) / 2, evenX = n / 2;
        long long oddY = (m + 1) / 2, evenY = m / 2;
        return oddX * evenY + evenX * oddY;
    }
};
