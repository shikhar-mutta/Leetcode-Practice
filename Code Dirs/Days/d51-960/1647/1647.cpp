// Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the length of the string s
    // SC: O(1) as we are using a constant size array of 26
    // Approach:
    // 1. Create a frequency array of size 26 to store the frequency of each character
    // 2. Sort the frequency array in descending order
    // 3. Iterate through the frequency array and for each frequency, check if it is greater than the previous frequency. If it is, then we need to delete some characters to make the frequencies unique. We can delete the difference between the current frequency and the previous frequency minus 1. We also need to make sure that the current frequency is not negative, so we take the maximum of the current frequency and 0. We add the number of deletions to the total deletions and update the current frequency to be the minimum of the current frequency and the previous frequency minus 1.
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int mindel = 0;
        for (int i = 1; i < 26; i++)
        {

            int bdel = freq[i];
            freq[i] = min(freq[i], max(freq[i - 1] - 1, 0));

            mindel += bdel - freq[i];
        }
        return mindel;
    }
};
