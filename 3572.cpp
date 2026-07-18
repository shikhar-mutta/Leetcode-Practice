// Link: https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
//  Approach:
//  1. We can find the maximum sum of distinct triplet by iterating through the array and keeping track of the maximum three values of y for distinct x values.
//  2. We can do this by maintaining three variables m1, m2, m3 to store the maximum three values of y and three variables i1, i2, i3 to store the indices of the corresponding x values.
//  3. We can then return the sum of m1, m2, and m3 if all three are non-zero, otherwise return -1.
#define db(...) logger(#__VA_ARGS__, __VA_ARGS__) /* */
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << endl;
}
class Solution
{
public:
    int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
    {
        int m1 = 0, m2 = 0, m3 = 0, i1 = -1, i2 = -1, i3 = -1, n = x.size();
        for (int i = 0; i < n; i++)
        {
            // db(m1, m2, m3);
            // db(i1, i2, i3);
            if (y[i] > m1)
            {
                if (i1 > -1 && x[i] != x[i1])
                {
                    if (i2 > -1 && x[i2] != x[i])
                    {
                        i3 = i2;
                        m3 = m2;
                    }
                    i2 = i1;
                    m2 = m1;
                }
                m1 = y[i];
                i1 = i;
            }
            if (y[i] > m2)
            {
                if (i1 > -1 && x[i] == x[i1])
                    continue;
                if (i2 > -1 && x[i2] != x[i])
                {
                    m3 = m2;
                    i3 = i2;
                }
                m2 = y[i];
                i2 = i;
            }
            if (y[i] > m3)
            {
                if ((i1 > -1 && x[i1] == x[i]) || (i2 > -1 && x[i2] == x[i]))
                    continue;
                m3 = y[i];
                i3 = i;
            }
        }
        if (!m1 || !m2 || !m3)
            return -1;
        return m1 + m2 + m3;
    }
};