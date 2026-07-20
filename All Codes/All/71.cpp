// Link: https://leetcode.com/problems/simplify-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input path string
    // SC: O(n) for the stack used to store the directories in the path
    // Approach:
    //  1. Use a stack to store the directories in the path.
    //  2. Iterate through the input path string and extract each directory name.
    //  3. If the directory name is ".", ignore it.
    //  4. If the directory name is "..", pop the top directory from the stack if the stack is not empty.
    //  5. If the directory name is a valid directory name, push it onto the stack.
    //  6. After processing the entire path string,
    //     construct the simplified path by popping the directories from the stack and concatenating them with "/" as the separator.

    string simplifyPath(string path)
    {
        stack<string> st;
        st.push("/");
        string ans = "";
        int i = 1;
        while (i < path.size())
        {
            string dir = "";
            while (i < path.size() && path[i] == '/')
                i++;
            while (i < path.size() && path[i] != '/')
            {
                dir += path[i];
                i++;
            }
            while (i < path.size() && path[i] == '/')
                i++;
            if (dir == ".")
                continue;
            else if (dir == "..")
            {
                if (st.size() > 1)
                {
                    st.pop();
                }
            }
            else
                st.push(dir);
        }
        while (st.size() > 1)
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if (!ans.size())
            ans = "/";
        return ans;
    }
};