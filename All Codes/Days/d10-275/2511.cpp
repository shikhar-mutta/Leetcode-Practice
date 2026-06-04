// Link: https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        int n = forts.size();
        int ans = 0;
        // Iterate through the forts array to find potential captures
        for (int i = 0; i < n; i++)
        {
            // Check if the current fort is occupied by either our forces (1) or no fort at all (-1)
            if (forts[i] == 1 || forts[i] == -1)
            {
                int target = -forts[i]; // looking for -1 if we're at 1, and vice versa
                int j = i + 1;
                while (j < n && forts[j] == 0) // Move forward through enemy forts
                    j++;
                if (j < n && forts[j] == target) // If we find the target fort, calculate the number of enemy forts captured
                    ans = max(ans, j - i - 1);
            }
        }
        return ans;
    }
};
