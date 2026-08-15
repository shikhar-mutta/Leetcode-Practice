// Link: https://leetcode.com/problems/integer-to-english-words/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: convert in groups of 3 digits (billions/millions/thousands/units), each group formatted
// by a helper handling hundreds/tens/ones, then joined with the appropriate scale word
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> below20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
            "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
            "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
            "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        function<string(int)> helper = [&](int n) -> string {
            if (n == 0) return "";
            if (n < 20) return below20[n] + " ";
            if (n < 100) return tens[n / 10] + " " + helper(n % 10);
            return below20[n / 100] + " Hundred " + helper(n % 100);
        };

        string res;
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                res = helper(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
            i++;
        }
        // trim extra spaces
        stringstream ss(res);
        string word, out;
        while (ss >> word) { if (!out.empty()) out += " "; out += word; }
        return out;
    }
};
