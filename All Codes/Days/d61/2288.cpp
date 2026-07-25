// Link: https://leetcode.com/problems/apply-discount-to-prices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), n = sentence.length()
// SC: O(n)
// Approach: split the sentence on spaces, and for each token that matches
// the price format ('$' followed by one or more digits, nothing else),
// apply the discount and reformat to exactly 2 decimal places; every other
// token is copied through unchanged.
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string word, result;
        bool first = true;

        while (ss >> word) {
            if (!first)
                result += ' ';
            first = false;

            if (isPrice(word)) {
                long long value = stoll(word.substr(1));
                double discounted = value * (100 - discount) / 100.0;
                char buf[64];
                snprintf(buf, sizeof(buf), "$%.2f", discounted);
                result += buf;
            } else {
                result += word;
            }
        }
        return result;
    }

private:
    bool isPrice(const string& w) {
        if (w.size() < 2 || w[0] != '$')
            return false;
        for (int i = 1; i < w.size(); ++i)
            if (!isdigit(w[i]))
                return false;
        return true;
    }
};
