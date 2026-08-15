// Link: https://leetcode.com/problems/maximum-font-to-fit-a-sentence-in-a-screen/description/

#include <bits/stdc++.h>
using namespace std;

class FontInfo {
public:
    virtual int getWidth(int fontSize, char ch) = 0;
    virtual int getHeight(int fontSize) = 0;
    virtual ~FontInfo() {}
};

class Solution {
public:
    bool fits(const string& text, int w, int h, int fontSize, FontInfo& fontInfo) {
        if (fontInfo.getHeight(fontSize) > h) return false;
        long long total = 0;
        for (char c : text) total += fontInfo.getWidth(fontSize, c);
        return total <= w;
    }

    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo& fontInfo) {
        int lo = 0, hi = (int)fonts.size() - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (fits(text, w, h, fonts[mid], fontInfo)) {
                ans = fonts[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
