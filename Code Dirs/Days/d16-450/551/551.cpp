// Link: https://leetcode.com/problems/student-attendance-record-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool checkRecord(string s)
    {
        int countA = 0, countL = 0;

        for (char c : s)
        {
            if (c == 'A')
            {
                countA++;
                countL = 0;
            }
            else if (c == 'L')
            {
                countL++;
                if (countL > 2)
                    return false;
            }
            else
                countL = 0;

            if (countA > 1)
                return false;
        }

        return true;
    }
};
