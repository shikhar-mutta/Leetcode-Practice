// Link: https://leetcode.com/problems/student-attendance-record-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: count absences, check for 3 consecutive lates
class Solution {
public:
    bool checkRecord(string s) {
        int absences = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'A') absences++;
            if (i + 2 < (int)s.size() && s[i] == 'L' && s[i+1] == 'L' && s[i+2] == 'L') return false;
        }
        return absences < 2;
    }
};
