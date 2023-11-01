#include <bits/stdc++.h>
using namespace std;

long long int n, max_n = INT_MAX;

void solve()
{
    double last_num = 1, current_chance = 1;

    
    n = std::min(n, max_n);

    for (int i = 2; i <= n; i++) {
        last_num /= i;

        int int_sign = (i % 2 == 1) ? 1 : -1;

        current_chance += int_sign * last_num;
    }

    cout << current_chance << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    solve();

    return 0;
}