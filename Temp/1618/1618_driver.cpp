#include <bits/stdc++.h>
using namespace std;
#include "1618.cpp"

class MockFontInfo : public FontInfo {
public:
    int getWidth(int fontSize, char ch) override {
        return fontSize;
    }
    int getHeight(int fontSize) override {
        return fontSize;
    }
};

int main() {
    Solution sol;

    {
        string text = "helloworld";
        int w = 100, h = 100;
        vector<int> fonts = {6, 8, 10, 12, 14, 16, 18, 24, 36};
        MockFontInfo fi;
        cout << sol.maxFont(text, w, h, fonts, fi) << "\n";
    }
    {
        string text = "leetcode";
        int w = 1000, h = 50;
        vector<int> fonts = {1, 2, 4};
        MockFontInfo fi;
        cout << sol.maxFont(text, w, h, fonts, fi) << "\n";
    }
    {
        string text = "easyquestion";
        int w = 100, h = 100;
        vector<int> fonts = {6, 8, 10, 12, 14, 16, 18, 24, 36};
        MockFontInfo fi;
        cout << sol.maxFont(text, w, h, fonts, fi) << "\n";
    }

    return 0;
}
