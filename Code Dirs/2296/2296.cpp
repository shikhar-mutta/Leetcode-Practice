// Link: https://leetcode.com/problems/design-a-text-editor/description/

#include <bits/stdc++.h>
using namespace std;

class TextEditor
{
    string left;  // text to the left of the cursor, in order
    string right; // text to the right of the cursor, reversed (back() = char just right of cursor)

    string lastTen()
    {
        return left.substr(max(0, (int)left.size() - 10));
    }

public:
    TextEditor() {}

    void addText(string text)
    {
        left += text;
    }

    int deleteText(int k)
    {
        int d = min((int)left.size(), k);
        left.erase(left.size() - d);
        return d;
    }

    string cursorLeft(int k)
    {
        while (k-- && !left.empty())
        {
            right.push_back(left.back());
            left.pop_back();
        }
        return lastTen();
    }

    string cursorRight(int k)
    {
        while (k-- && !right.empty())
        {
            left.push_back(right.back());
            right.pop_back();
        }
        return lastTen();
    }
};
