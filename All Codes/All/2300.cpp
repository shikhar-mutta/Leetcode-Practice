// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) where n is the size of spells and m is the size of potions.
    // SC: O(m) where m is the size of potions.
    //  Approach:
    //  1. We will create a frequency array of size 100001 to store the frequency of each potion.
    //  2. We will iterate through the potions and increment the frequency of each potion in the frequency array.
    //  3. We will create a prefix sum of the frequency array to get the number of potions less than or equal to each potion.
    //  4. We will iterate through the spells and for each spell, we will calculate the minimum potion required to make the product of spell and potion greater than or equal to success.
    //  5. We will use the prefix sum to get the number of potions less than the minimum potion required and subtract it from the total number of potions to get the number of successful pairs for that spell.
    // 6. We will return the result array containing the number of successful pairs for each spell.
    static vector<int> successfulPairs(vector<int> &spells,
                                       vector<int> &potions,
                                       long long success)
    {

        int freq[100001] = {0}, pMax = 0;

        for (int p : potions)
        {
            freq[p]++;
            pMax = max(pMax, p);
        }

        // Prefix sum for frequency
        partial_sum(freq, freq + pMax + 1, freq);

        const int n = spells.size(), m = potions.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++)
        {
            const int spell = spells[i];
            const long long k = (success + spell - 1) / spell;

            if (k <= pMax)
            {
                result[i] = m - (k > 1 ? freq[k - 1] : 0);
            }
        }

        return result;
    }
};