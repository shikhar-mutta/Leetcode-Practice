// Link: https://leetcode.com/problems/number-of-senior-citizens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n), SC: O(1)
    int countSeniors(vector<string> &details)
    {
        int count = 0;
        for (string &detail : details)
        {
            int age = stoi(detail.substr(11, 2));
            if (age > 60)
            {
                count++;
            }
        }
        return count;
    }
};
