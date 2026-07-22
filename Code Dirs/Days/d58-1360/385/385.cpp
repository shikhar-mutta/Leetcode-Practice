// Link: https://leetcode.com/problems/mini-parser/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input string
// SC: O(n) where n is the length of the input string, as we are using recursion to build the NestedInteger structure
// Approach:
//  1. We will use a recursive approach to build the NestedInteger structure.
//  2. We will use an istringstream to read the input string character by character
//  3. If we encounter a number, we will create a NestedInteger with that number
//  4. If we encounter a '[', we will create a NestedInteger list and recursively add elements to it until we encounter a ']'
//  5. If we encounter a ',', we will skip it and continue to the next element
//  6. Finally, we will return the NestedInteger structure built from the input string.

class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        istringstream in(s);
        return deserialize(in);
    }

private:
    NestedInteger deserialize(istringstream &in)
    {
        int number;
        if (in >> number)
            return NestedInteger(number);
        in.clear();
        in.get();
        NestedInteger list;
        while (in.peek() != ']')
        {
            list.add(deserialize(in));
            if (in.peek() == ',')
                in.get();
        }
        in.get();
        return list;
    }
};