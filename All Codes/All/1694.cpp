// Link: https://leetcode.com/problems/reformat-phone-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string reformatNumber(string number)
    {
        // keep only digits
        string d;
        for (char c : number)
            if (isdigit((unsigned char)c))
                d += c;

        string res;
        int i = 0, n = d.size();
        while (n - i > 4)
        { // take blocks of 3 while >4 remain
            res += d.substr(i, 3) + "-";
            i += 3;
        }
        int rem = n - i;
        if (rem == 4)
            res += d.substr(i, 2) + "-" + d.substr(i + 2, 2); // 4 -> 2+2
        else
            res += d.substr(i); // 2 or 3 left -> one block
        return res;
    }
};
