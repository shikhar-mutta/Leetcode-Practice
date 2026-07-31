// Link: https://leetcode.com/problems/tag-validator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: single left-to-right scan with a stack of open tag names.
//  At each '<': check for CDATA (skip verbatim to the first "]]>"), an
//  end tag (must match stack top, pop, and if the stack empties nothing
//  may follow), or a start tag (validate name, push). Any character
//  outside an open tag, or leftover unbalanced stack, invalidates.
class Solution
{
public:
    bool isValidTag(string &s)
    {
        if (s.size() < 1 || s.size() > 9)
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (!isupper(s[i]))
                return false;
        }
        return true;
    }
    bool isValid(string code)
    {
        int n = code.size();
        stack<string> st;
        for (int i = 0; i < n; i++)
        {
            // there should be atleast one tag from the begining
            if (i > 0 && st.empty())
            {
                return false;
            }

            // handle CDATA section
            if (code.substr(i, 9) == "<![CDATA[")
            {
                int pos = code.find("]]>", i + 9);
                if (pos == -1)
                    return false;
                // skip the content part and CDATA clsoing
                i = pos + 2;
            }

            // check closing
            else if (code.substr(i, 2) == "</")
            {
                int endTagPos = code.find('>', i + 2);
                if (endTagPos == -1)
                    return false;

                // extract tag name
                string tag = code.substr(i + 2, endTagPos - (i + 2));

                // validate end tag
                if (st.empty() || !isValidTag(tag) || st.top() != tag)
                {
                    return false;
                }

                st.pop();
                i = endTagPos;
            }

            // handle opening tag
            else if (code[i] == '<')
            {
                int startTagPos = code.find('>', i + 1);
                if (startTagPos == -1)
                    return false;

                // extract tag name
                string tag = code.substr(i + 1, startTagPos - (i + 1));

                if (!isValidTag(tag))
                {
                    return false;
                }
                st.push(tag);
                i = startTagPos;
            }
        }
        return st.empty();
    }
};