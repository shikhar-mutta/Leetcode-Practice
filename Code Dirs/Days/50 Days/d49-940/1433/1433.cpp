// Link: https://leetcode.com/problems/check-if-a-string-can-break-another-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) for sorting both strings.
    // SC: O(n) for storing the sorted strings.
    //  Approach:
    //  1. Sort both strings s1 and s2.
    //  2. Compare the characters of both sorted strings.
    bool checkIfCanBreak(string s1, string s2)
    {
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        vector<int> hashMap(26, 0);
        for (char ch : s1)
        {
            hashMap[ch - 'a']++;
        }
        int j = 0;
        for (int i = 0; i < 26; i++)
        {
            int cnt = hashMap[i];
            while (cnt--)
            {
                s1[j++] = char('a' + i);
            }
            hashMap[i] = 0;
        }
        for (char ch : s2)
        {
            hashMap[ch - 'a']++;
        }
        j = 0;
        for (int i = 0; i < 26; i++)
        {
            int cnt = hashMap[i];
            while (cnt--)
            {
                s2[j++] = char('a' + i);
            }
        }
        int n = s1.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] > s2[i])
                a++;
            else if (s2[i] > s1[i])
                b++;
        }
        return (a == 0 || b == 0) ? true : false;
    }
};