#include <bits/stdc++.h>
using namespace std;

#include "54.cpp"


struct TeeBuf : std::streambuf {
    std::streambuf *orig, *echo;
    TeeBuf(std::streambuf* o, std::streambuf* e) : orig(o), echo(e) {}
    int_type uflow() override {
        int_type c = orig->sbumpc();
        if (c != traits_type::eof()) echo->sputc(c);
        return c;
    }
    int_type underflow() override { return orig->sgetc(); }
    std::streamsize xsgetn(char* s, std::streamsize n) override {
        std::streamsize got = orig->sgetn(s, n);
        echo->sputn(s, got);
        return got;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.rdbuf(new TeeBuf(cin.rdbuf(), cerr.rdbuf()));
    while (t--) {
        struct Guard { ~Guard() { cerr << "\n---\n"; } } _guard;
        int m, n;
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        Solution sol;
        vector<int> ans = sol.spiralOrder(matrix);
        for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
    return 0;
}
