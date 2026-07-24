// Link: https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach:
//  1. We can use a frequency array to count the frequency of each character in both strings.
//  2. We can then use the frequency array to calculate the minimum number of characters that need to be changed to satisfy one of the three conditions.
//  3. We can use a prefix sum array to calculate the number of characters that need to be changed to satisfy the first two conditions.
//  Note: We need to check all three conditions and return the minimum number of characters that need to be changed.
class Solution
{
public:
    int minCharacters(string a, string b)
    {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (char ch : a)
        {
            freq1[ch - 'a']++;
        }
        for (char ch : b)
        {
            freq2[ch - 'a']++;
        }
        int ans = INT_MAX;
        int n1 = a.size();
        int n2 = b.size();
        for (int i = 0; i < 26; i++)
        {
            ans = min(ans, n1 - freq1[i] + n2 - freq2[i]);
        }

        vector<int> pre1(26, 0);
        vector<int> pre2(26, 0);
        pre1[0] = freq1[0];
        pre2[0] = freq2[0];
        for (int i = 1; i < 26; i++)
        {
            pre1[i] += pre1[i - 1] + freq1[i];
            pre2[i] += pre2[i - 1] + freq2[i];
        }

        for (int i = 0; i < 25; i++)
        {
            int a1 = n1 - pre1[i] + pre2[i];
            ans = min(ans, a1);
            int a2 = n2 - pre2[i] + pre1[i];
            ans = min(ans, a2);
        }
        return ans;
    }
};
