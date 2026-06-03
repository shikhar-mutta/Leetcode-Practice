// Link: https://leetcode.com/problems/finding-3-digit-even-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Frequency Count TC: O(n) SC: O(1)
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        // Count the frequency of each digit in the input array
        int freq[10] = {};
        for (int d : digits)
            freq[d]++;

        vector<int> ans;
        for (int num = 100; num <= 998; num += 2)
        {
            // Extract the hundreds, tens, and units digits of the current number
            int a = num / 100, b = (num / 10) % 10, c = num % 10;
            freq[a]--;
            freq[b]--;
            freq[c]--;
            // Check if non neg freq of all 3 digits then add to ans
            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0)
                ans.push_back(num);
            // restore freq for next iteration
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }
        return ans;
    }
    // Approach 2: Brute Force TC: O(n^3 log n) SC: O(n)
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> ans;
        for (int i = 0; i < digits.size(); i++)
            for (int j = 0; j < digits.size(); j++)
                for (int k = 0; k < digits.size(); k++)
                    if (i != j && i != k && j != k)
                    {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (num >= 100 && num % 2 == 0)
                            ans.push_back(num);
                    }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
