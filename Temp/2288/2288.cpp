// Link: https://leetcode.com/problems/apply-discount-to-prices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrice(const string& w) {
        if (w.size() < 2 || w[0] != '$') return false;
        for (int i = 1; i < (int)w.size(); i++) if (!isdigit(w[i])) return false;
        return true;
    }

    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) result += ' ';
            if (isPrice(word)) {
                double price = stod(word.substr(1));
                double newPrice = price * (100 - discount) / 100.0;
                ostringstream oss;
                oss << fixed << setprecision(2) << newPrice;
                result += '$' + oss.str();
            } else {
                result += word;
            }
        }
        return result;
    }
};
