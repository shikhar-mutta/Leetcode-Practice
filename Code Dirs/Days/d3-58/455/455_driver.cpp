#include <bits/stdc++.h>
using namespace std;

#include "455.cpp"


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
        int n;
        cin >> n;
        vector<int> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];
        int m;
        cin >> m;
        vector<int> s(m);
        for (int i = 0; i < m; i++) cin >> s[i];
        Solution sol;
        cout << sol.findContentChildren(g, s) << "\n";
    }
    return 0;
}
