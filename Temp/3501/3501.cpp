// Link: https://leetcode.com/problems/maximize-active-section-with-trade-ii/description/

#include <bits/stdc++.h>
using namespace std;

const int K3501 = 17, MAXN3501 = 1e5;
int st3501[K3501 + 1][MAXN3501];

void build3501(auto& array) {
    copy(array.begin(), array.end(), st3501[0]);

    for (int i = 1; i <= K3501; i++)
        for (int j = 0; j + (1 << i) <= (int)array.size(); j++)
            st3501[i][j] = max(st3501[i - 1][j], st3501[i - 1][j + (1 << (i - 1))]);
}

int query3501(int L, int R) {
    int i = bit_width(unsigned(R - L + 1)) - 1;
    return max(st3501[i][L], st3501[i][R - (1 << i) + 1]);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size(), active = 0;
        vector<pair<int, int>> zero;
        vector<int> index(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i > 0 && s[i - 1] == '0')
                    zero.back().second++;
                else
                    zero.push_back({i, 1});
            } else {
                active++;
            }
            index[i] = int(zero.size()) - 1;
        }
        if (zero.empty())
            return vector<int>(queries.size(), active);

        vector<int> gains(zero.size() - 1);
        for (int i = (int)zero.size() - 2; i >= 0; i--) {
            gains[i] = zero[i].second + zero[i + 1].second;
        }
        build3501(gains);

        vector<int> res(queries.size(), active);
        for (int i = 0, sz = queries.size(); i < (int)queries.size(); i++) {
            int L = queries[i][0], R = queries[i][1];
            int start = index[L] + 1, end = index[R] - (s[R] == '0');
            int cnt_left = index[L] == -1 ? -1 : (zero[index[L]].second - (L - zero[index[L]].first));
            int cnt_right = index[R] == -1 ? -1 : (R - zero[index[R]].first + 1);

            if (start < end)
                res[i] = max(res[i], active + query3501(start, end - 1));
            if (s[L] == '0' && s[R] == '0' && index[L] + 1 == index[R])
                res[i] = max(res[i], active + cnt_left + cnt_right);
            if (s[L] == '0' && index[L] + 1 < index[R] + (s[R] == '1'))
                res[i] = max(res[i], active + cnt_left + zero[index[L] + 1].second);
            if (s[R] == '0' && index[L] < index[R] - 1)
                res[i] = max(res[i], active + cnt_right + zero[index[R] - 1].second);
        }
        return res;
    }
};
