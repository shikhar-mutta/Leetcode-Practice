// Link: https://leetcode.com/problems/count-beautiful-substrings-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(k)), SC: O(n * sqrt(k))
//  Approach: We can use a 2D vector to store the count of prefixes with specific properties. We first factorize k to find kk, which is the product of the prime factors of k raised to the power of half their count (rounded up). We then initialize a 2D vector of size kk x (2 * n + 1) to store the counts of prefixes with specific properties. We iterate through the string, counting the number of vowels and consonants, and for each prefix, we calculate the corresponding x and y values based on the number of vowels and consonants. We then add the count of previously seen valid prefixes to the answer and register the current prefix in the matrix. Finally, we return the total count of beautiful substrings.
class Solution
{
public:
    long long beautifulSubstrings(string s, int k)
    {
        int n = s.length();

        // Step 1: Factorize k to find kk
        long long kk = 1;
        long long temp_k = k;

        for (long long x = 2; x * x <= temp_k; ++x)
        {
            if (temp_k % x == 0)
            {
                int count = 0;
                while (temp_k % x == 0)
                {
                    count++;
                    temp_k /= x;
                }
                long long power = (count + 1) / 2;
                long long mult = 1;
                for (int i = 0; i < power; ++i)
                {
                    mult *= x;
                }
                kk *= mult;
            }
        }

        if (temp_k > 1)
        {
            kk *= temp_k;
        }

        // Step 2: 2D Vector initialization
        // x dimension: modulo kk (size kk)
        // y dimension: v - c. Range is [-n, n], so size needs to be 2 * n + 1.
        // Offset is n.
        vector<vector<int>> matrix(kk, vector<int>(2 * n + 1, 0));

        // Base case: empty string (v = 0, c = 0)
        matrix[0][n] = 1;

        int v = 0;
        int c = 0;
        long long ans = 0;

        for (char ch : s)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                v++;
            }
            else
            {
                c++;
            }

            // x = vowels modulo kk
            int x = v % kk;
            // y = (vowels - consonants) + offset
            int y = (v - c) + n;

            // Add the number of previously seen valid prefixes to the answer
            ans += matrix[x][y];

            // Register the current prefix in the matrix
            matrix[x][y]++;
        }

        return ans;
    }
};
