// Link: https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: greedy — for each number, prefer appending to an existing subsequence ending at num-1; otherwise start a new subsequence if num+1 and num+2 are available; otherwise fail.
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> count, tail;
        for (int x : nums) count[x]++;
        for (int x : nums) {
            if (count[x] == 0) continue;
            count[x]--;
            if (tail[x-1] > 0) {
                tail[x-1]--;
                tail[x]++;
            } else if (count[x+1] > 0 && count[x+2] > 0) {
                count[x+1]--;
                count[x+2]--;
                tail[x+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};
