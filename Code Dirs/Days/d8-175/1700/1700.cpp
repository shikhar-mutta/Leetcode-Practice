// Link: https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int count0 = 0, count1 = 0;
        for (int s : students)
        {
            if (s == 0) // Count the number of students who prefer sandwich type 0
                count0++;
            else // Count the number of students who prefer sandwich type 1
                count1++;
        }

        for (int s : sandwiches)
        {
            if (s == 0) // If the sandwich is of type 0, try to serve a student who prefers type 0
            {
                if (count0 > 0)
                    count0--;
                else
                    break;
            }
            else
            { // If the sandwich is of type 1, try to serve a student who prefers type 1
                if (count1 > 0)
                    count1--;
                else
                    break;
            }
        }

        return count0 + count1;
    }
};
