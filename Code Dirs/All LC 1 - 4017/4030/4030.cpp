// Link: https://leetcode.com/problems/check-ascii-palindromic/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindromic(string s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            // compare the i-th character from the start and the i-th character from the end
            int j = n - 1 - i;
            unsigned char a = s[i];
            unsigned char b = s[j];

            // reverse the 8 bits of b
            unsigned char rev = 0;
            for (int k = 0; k < 8; k++)
            { // check if the k-th bit of b is set
                if (b & (1 << k))
                    rev |= (1 << (7 - k)); // set the (7-k)-th bit of rev
            }
            
            if (a != rev)
                return false;
        }

        // if n is odd, the middle character's own byte must be a palindrome
        if (n % 2 == 1)
        {
            unsigned char mid = s[n / 2];
            unsigned char rev = 0;
            for (int k = 0; k < 8; k++)
            {
                if (mid & (1 << k))
                    rev |= (1 << (7 - k));
            }
            if (mid != rev)
                return false;
        }
        
        return true;
    }
};
