// Link: https://leetcode.com/problems/strong-password-checker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: classic 3-case solution - too short just needs insertions
// (missing char types dominate); too long needs deletions prioritized on
// runs where mod3==0 (delete 1), then mod3==1 (delete 2), then mod3==2
// (delete 3, i.e. two deletions per 3-run); in-range needs max(missing
// types, replacements for repeat runs)
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
        int missingTypes = (!hasLower) + (!hasUpper) + (!hasDigit);

        vector<int> runLengths;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && password[j] == password[i]) j++;
            if (j - i >= 3) runLengths.push_back(j - i);
            i = j;
        }

        if (n < 6) {
            return max(missingTypes, 6 - n);
        }

        if (n <= 20) {
            int replacements = 0;
            for (int len : runLengths) replacements += len / 3;
            return max(missingTypes, replacements);
        }

        // n > 20: need deletions
        int deletions = n - 20;
        int remainingDeletions = deletions;

        // priority 1: runs with len%3==0, one deletion drops replace count by 1
        for (int& len : runLengths) {
            if (remainingDeletions <= 0) break;
            if (len % 3 == 0) { len--; remainingDeletions--; }
        }
        // priority 2: runs with len%3==1, two deletions drop replace count by 1
        for (int& len : runLengths) {
            if (remainingDeletions <= 0) break;
            if (len % 3 == 1 && len > 2) {
                int use = min(remainingDeletions, 2);
                len -= use;
                remainingDeletions -= use;
            }
        }
        // priority 3: remaining deletions, 3 deletions drop replace count by 1
        for (int& len : runLengths) {
            if (remainingDeletions <= 0) break;
            if (len >= 3) {
                int use = min(remainingDeletions, len - 2);
                len -= use;
                remainingDeletions -= use;
            }
        }

        int replacements = 0;
        for (int len : runLengths) if (len >= 3) replacements += len / 3;

        return deletions + max(missingTypes, replacements);
    }
};
