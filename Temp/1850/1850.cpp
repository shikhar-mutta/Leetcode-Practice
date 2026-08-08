// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        while (k--) next_permutation(target.begin(), target.end());

        int swaps = 0;
        string cur = num;
        for (int i = 0; i < (int)cur.size(); i++) {
            if (cur[i] == target[i]) continue;
            int j = i + 1;
            while (cur[j] != target[i]) j++;
            while (j > i) { swap(cur[j], cur[j-1]); j--; swaps++; }
        }
        return swaps;
    }
};
