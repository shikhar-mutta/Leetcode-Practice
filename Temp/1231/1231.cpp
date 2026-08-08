// Link: https://leetcode.com/problems/divide-chocolate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int lo = *min_element(sweetness.begin(), sweetness.end());
        int hi = accumulate(sweetness.begin(), sweetness.end(), 0) / (k + 1);

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            int pieces = 0, cur = 0;
            for (int s : sweetness) {
                cur += s;
                if (cur >= mid) { pieces++; cur = 0; }
            }
            if (pieces >= k + 1) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
