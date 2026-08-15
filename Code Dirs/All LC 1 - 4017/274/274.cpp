// Link: https://leetcode.com/problems/h-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(1)
// Approach: sort descending, h is the largest index+1 where citations[i] >= i+1
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < (int)citations.size(); i++) {
            if (citations[i] >= i + 1) h = i + 1;
            else break;
        }
        return h;
    }
};
