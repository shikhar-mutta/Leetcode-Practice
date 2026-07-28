// Link: https://leetcode.com/problems/strong-password-checker/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: classic construction. Count missing character-type
// categories (lower/upper/digit) and find runs of 3+ repeated chars.
// If too long, prefer deletions on runs with len%3==0, then %3==1,
// which each save a needed replacement; remaining deletions still cut
// replacements at a rate of 1 per 3 deleted. Then take
// deletions + max(missing types, remaining replacements needed), or for
// short/valid-length passwords max(missing, insertions-for-length, replacements).
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (char c : password) {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
        }
        int missing = (!hasLower) + (!hasUpper) + (!hasDigit);

        vector<int> runs;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && password[j] == password[i]) j++;
            int len = j - i;
            if (len >= 3) runs.push_back(len);
            i = j;
        }

        if (n < 6) {
            return max(missing, 6 - n);
        } else if (n <= 20) {
            int replace = 0;
            for (int len : runs) replace += len / 3;
            return max(missing, replace);
        } else {
            int deleteCount = n - 20;
            int remainingDelete = deleteCount;

            // priority 1: runs with len % 3 == 0
            for (int& len : runs) {
                if (remainingDelete <= 0) break;
                if (len % 3 == 0) { len--; remainingDelete--; }
            }
            // priority 2: runs with len % 3 == 1
            for (int& len : runs) {
                if (remainingDelete <= 0) break;
                if (len % 3 == 1 && len > 2) {
                    int use = min(remainingDelete, 2);
                    len -= use;
                    remainingDelete -= use;
                }
            }
            // priority 3: remaining deletions, 3 at a time
            for (int& len : runs) {
                if (remainingDelete <= 0) break;
                if (len >= 3) {
                    int use = min(remainingDelete, len - 2);
                    len -= use;
                    remainingDelete -= use;
                }
            }

            int replace = 0;
            for (int len : runs) if (len >= 3) replace += len / 3;

            return deleteCount + max(missing, replace);
        }
    }
};
