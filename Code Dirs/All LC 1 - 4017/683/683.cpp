// Link: https://leetcode.com/problems/k-empty-slots/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: days[pos] = bloom day for flower at that position. Sliding window [left, right=left+k+1]; scan i across the window's interior — if days[i] is smaller than both endpoints, it invalidates the window early (jump left to i); if i reaches right with all interior days greater than both endpoints, the window qualifies on day max(days[left], days[right]).
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> days(n);
        for (int i = 0; i < n; i++) days[bulbs[i]-1] = i+1;
        int ans = INT_MAX;
        int left = 0, right = k+1;
        for (int i = 0; right < n; i++) {
            if (days[i] < days[left] || days[i] <= days[right]) {
                if (i == right) ans = min(ans, max(days[left], days[right]));
                if (days[i] <= days[right]) {
                    left = i;
                    right = i + k + 1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
