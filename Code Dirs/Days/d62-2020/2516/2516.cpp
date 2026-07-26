// Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: minimizing total characters removed from the two ends is
// equivalent to maximizing the length of an untouched middle window that
// still leaves at least k of each character outside it. So fix the
// window's right boundary i (shrinking from the right end inward) and
// slide its left boundary j so the remaining counts outside [j+1, i]
// stay >= k for all three letters; track the best (smallest) total
// removed = i + (n-1-j) over all valid windows.
class Solution {
public:
    int takeCharacters(string s, int k) {
        int ca = 0, cb = 0, cc = 0;
        int n = s.size();
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ca++;
            if (s[i] == 'b')
                cb++;
            if (s[i] == 'c')
                cc++;
        }
        if (ca < k || cb < k || cc < k)
            return -1;
        int i = n - 1, j = n - 1;
        while (i >= 0) {
            if (s[i] == 'a')
                ca--;
            if (s[i] == 'b')
                cb--;
            if (s[i] == 'c')
                cc--;
            while (ca < k || cb < k || cc < k) {
                if (s[j] == 'a')
                    ca++;
                if (s[j] == 'b')
                    cb++;
                if (s[j] == 'c')
                    cc++;
                j--;
            }
            ans = min(ans, i + n - 1 - j);
            i--;
        }
        return ans;
    }
};
