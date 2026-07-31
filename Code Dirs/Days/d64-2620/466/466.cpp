// Link: https://leetcode.com/problems/count-the-repetitions/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(|s1| * |s2|)  SC: O(|s2|)
// Approach: greedily scan copies of s1, matching characters against a
// cyclic pointer into s2, tracking how many full s2's complete after
// each s1 copy. Record (s2-pointer -> (copyIndex, s2CountSoFar)) to
// detect a repeating cycle; once found, use the cycle's period to
// extrapolate over the remaining s1 copies, then simulate the leftover.
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        int len1 = s1.size(), len2 = s2.size();
        unordered_map<int, pair<int, int>> seen; // s2ptr -> (copyIdx, s2CountSoFar)

        int s2ptr = 0;
        long long s2Count = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 0; j < len1; j++)
            {
                if (s1[j] == s2[s2ptr])
                {
                    s2ptr++;
                    if (s2ptr == len2)
                    {
                        s2ptr = 0;
                        s2Count++;
                    }
                }
            }
            if (seen.count(s2ptr))
            {
                auto [prevI, prevCount] = seen[s2ptr];
                int cycleLen = i - prevI;
                long long cycleCount = s2Count - prevCount;
                long long remaining = n1 - i;
                long long numCycles = remaining / cycleLen;
                long long totalS2Count = s2Count + numCycles * cycleCount;
                int rem = remaining % cycleLen;
                // simulate `rem` more copies from current state
                for (int r = 0; r < rem; r++)
                {
                    for (int j = 0; j < len1; j++)
                    {
                        if (s1[j] == s2[s2ptr])
                        {
                            s2ptr++;
                            if (s2ptr == len2)
                            {
                                s2ptr = 0;
                                totalS2Count++;
                            }
                        }
                    }
                }
                return (int)(totalS2Count / n2);
            }
            seen[s2ptr] = {i, (int)s2Count};
        }
        return (int)(s2Count / n2);
    }
};
