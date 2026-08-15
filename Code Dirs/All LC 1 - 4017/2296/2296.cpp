// Link: https://leetcode.com/problems/design-a-text-editor/description/

#include <bits/stdc++.h>
using namespace std;

class TextEditor {
    string left, right; // right stored reversed (right.back() = char immediately after cursor)

    string last10() {
        int n = left.size();
        int start = max(0, n - 10);
        return left.substr(start, n - start);
    }
public:
    TextEditor() {}

    void addText(string text) {
        left += text;
    }

    int deleteText(int k) {
        int n = left.size();
        int remove = min(k, n);
        left.resize(n - remove);
        return remove;
    }

    string cursorLeft(int k) {
        int n = left.size();
        int move = min(k, n);
        for (int i = 0; i < move; i++) {
            right.push_back(left.back());
            left.pop_back();
        }
        return last10();
    }

    string cursorRight(int k) {
        int n = right.size();
        int move = min(k, n);
        for (int i = 0; i < move; i++) {
            left.push_back(right.back());
            right.pop_back();
        }
        return last10();
    }
};
