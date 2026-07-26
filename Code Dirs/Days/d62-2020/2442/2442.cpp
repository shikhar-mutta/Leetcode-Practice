// Link: https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * d) where d = number of digits (~7) per element
// SC: O(1000001) for the presence bitset
// Approach: the resulting set is just the original numbers plus each
// number's digit-reversal, so mark both a[i] and its reversed digit
// value k in a fixed-size presence bitset (values bounded by 1e6),
// counting each newly-seen value once.
class Solution {
public:
    int countDistinctIntegers(vector<int>& a) {
        bitset<1000001> c;
        int m = 0;
        for (int i = 0, n = a.size(); i < n; ++i) {
            int k = 0;
            for (int j = a[i]; j; k = k * 10 + j % 10, j /= 10)
                ;
            m += !c[a[i]], c[a[i]] = 1, m += !c[k], c[k] = 1;
        }
        return m;
    }
};
