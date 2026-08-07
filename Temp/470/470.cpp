// Link: https://leetcode.com/problems/implement-rand10-using-rand7/description/

#include <bits/stdc++.h>
using namespace std;

int rand7();

// TC: O(1) expected  SC: O(1)
// Approach: rejection sampling - build a uniform value in [1,49] from two
// rand7() calls, reject values > 40, map remainder to [1,10]
class Solution {
public:
    int rand10() {
        int val;
        do {
            val = (rand7() - 1) * 7 + rand7();
        } while (val > 40);
        return (val - 1) % 10 + 1;
    }
};
