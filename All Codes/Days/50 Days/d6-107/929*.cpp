// Link: https://leetcode.com/problems/unique-email-addresses/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        // Approach 1: using two pointers
        unordered_set<string> uniqueEmails;
        for (const string &email : emails)
        {
            string local, domain;
            int i = 0, n = email.size();
            // get local
            while (i < n && email[i] != '@') // while not '@'
            {
                if (email[i] == '+') // skip until '@'
                {
                    while (i < n && email[i] != '@')
                        i++;
                    break;
                }
                if (email[i] != '.') // skip '.'
                    local += email[i];
                i++;
            }
            i++; // skip '@'
            // get domain
            while (i < n)
            {
                domain += email[i];
                i++;
            }
            uniqueEmails.insert({local + "@" + domain});
        }
        return uniqueEmails.size();

        // // Approach 2: using string functions
        // unordered_set<string> uniqueEmails;
        // for (const string &email : emails)
        // {
        //     int at = email.find('@');
        //     // if there is a '+', we take the substring until the '+', otherwise we take the substring until the '@'
        //     string local = email.substr(0, email.find('+', 0) < at ? email.find('+') : at);
        //     string domain = email.substr(at + 1);                              // get the domain
        //     local.erase(remove(local.begin(), local.end(), '.'), local.end()); // remove all '.' from the local part
        //     uniqueEmails.insert(local + "@" + domain);                         // insert the processed email into the set
        // }
        // return uniqueEmails.size();
    }
};
