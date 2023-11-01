#include <bits/stdc++.h>
using namespace std;

void solve()
{
    unordered_map<char, int> umap;

    umap[' '] = 0;
    umap['&'] = 24;
    umap[','] = 7;
    umap['2'] = 22;
    umap['8'] = 23;
    umap['>'] = 10;
    umap['D'] = 26;
    umap['J'] = 18;
    umap['P'] = 23;
    umap['V'] = 19;
    umap['\\'] = 10;
    umap['b'] = 25;
    umap['h'] = 21;
    umap['n'] = 18;
    umap['t'] = 17;
    umap['z'] = 19;
    umap['!'] = 9;
    umap['\''] = 3;
    umap['-'] = 7;
    umap['3'] = 23;
    umap['9'] = 26;
    umap['?'] = 15;
    umap['E'] = 26;
    umap['K'] = 21;
    umap['Q'] = 31;
    umap['W'] = 26;
    umap[']'] = 18;
    umap['c'] = 17;
    umap['i'] = 15;
    umap['o'] = 20;
    umap['u'] = 17;
    umap['{'] = 18;
    umap['"'] = 6;
    umap['('] = 12;
    umap['.'] = 4;
    umap['4'] = 21;
    umap[':'] = 8;
    umap['@'] = 32;
    umap['F'] = 20;
    umap['L'] = 16;
    umap['R'] = 28;
    umap['X'] = 18;
    umap['^'] = 7;
    umap['d'] = 25;
    umap['j'] = 20;
    umap['p'] = 25;
    umap['v'] = 13;
    umap['|'] = 12;
    umap['#'] = 24;
    umap[')'] = 12;
    umap['/'] = 10;
    umap['5'] = 27;
    umap[';'] = 11;
    umap['A'] = 24;
    umap['G'] = 25;
    umap['M'] = 28;
    umap['S'] = 25;
    umap['Y'] = 14;
    umap['_'] = 8;
    umap['e'] = 23;
    umap['k'] = 21;
    umap['q'] = 25;
    umap['w'] = 19;
    umap['}'] = 18;
    umap['$'] = 29;
    umap['*'] = 17;
    umap['0'] = 22;
    umap['6'] = 26;
    umap['<'] = 10;
    umap['B'] = 29;
    umap['H'] = 25;
    umap['N'] = 25;
    umap['T'] = 16;
    umap['Z'] = 22;
    umap['`'] = 3;
    umap['f'] = 18;
    umap['l'] = 16;
    umap['r'] = 13;
    umap['x'] = 13;
    umap['~'] = 9;
    umap['%'] = 22;
    umap['+'] = 13;
    umap['1'] = 19;
    umap['7'] = 16;
    umap['='] = 14;
    umap['C'] = 20;
    umap['I'] = 18;
    umap['O'] = 26;
    umap['U'] = 23;
    umap['['] = 18;
    umap['a'] = 23;
    umap['g'] = 30;
    umap['m'] = 22;
    umap['s'] = 21;
    umap['y'] = 24;
    string line;
    
    while (getline(cin, line))
    {
        int result = 0;

        for (int a : line) {
            result += umap[a];
        }

        cout << result << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}