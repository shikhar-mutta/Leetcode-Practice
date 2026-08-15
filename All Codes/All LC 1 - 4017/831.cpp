// Link: https://leetcode.com/problems/masking-personal-information/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach:
    //  1. We can check if the input string contains an '@' character to determine if it is an email address or a phone number.
    //  2. If it is an email address, we can convert the entire string to lowercase and then extract the name and domain parts of the email address. We can then return the masked email address in the format "first character of name + "*****" + last character of name + "@" + domain".
    //  3. If it is a phone number, we can extract all the digits from the input string and then format the phone number in the format "***-***-last 4 digits" if it is a local number, or "+country code-***-***-last 4 digits" if it is an international number. We can return the masked phone number in the appropriate format.
    //  4. Finally, we can return the masked email address or phone number as the output.
    string maskPII(string s)
    {
        auto atPos = s.find('@');
        if (atPos != string::npos)
        {
            for (auto &c : s)
                c = tolower(c);
            string name = s.substr(0, atPos);
            string domain = s.substr(atPos + 1);
            return string(1, name.front()) + "*****" + name.back() + "@" + domain;
        }

        string digits;
        for (char c : s)
            if (isdigit(c))
                digits += c;
        int n = digits.size();
        string local = "***-***-" + digits.substr(n - 4);
        if (n == 10)
            return local;
        int countryLen = n - 10;
        return "+" + string(countryLen, '*') + "-" + local;
    }
};
