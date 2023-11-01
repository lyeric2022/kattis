#include <bits/stdc++.h>
using namespace std;

int n, q;

void solve()
{
    int h, v, prev = 1;
    vector<int> vect(1000000000, 0);

    for (int i = 0; i < n; i++) {
        cin >> h >> v;
        vect[h] += v;
    }

    for (int j = 0; j < q; j++) {
        cin >> h >> v;
        int v_avai = 0;

        for (int i = h - 1000; i <= h + 1000; i++) {
            if (i < 1) {
                i = 1;
            }

            if (i > prev - 1000) {
                i = prev;
            }

            v_avai += vect[i];
        }

        prev = j;

        // cout << v_avai << " " << v << "\n";

        cout << ((v_avai >= v) ? "yes": "no") << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    solve();

    return 0;
}