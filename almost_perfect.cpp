#include <bits/stdc++.h>
using namespace std;

int n;

void solve()
{
    while (cin >> n)
    {
        int divisor_sum = 1;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                divisor_sum += i;
                
                if (i != n / i)
                {
                    divisor_sum += n / i;
                }
            }
        }

        cout << n;

        if (divisor_sum == n)
        {
            cout << " perfect";
        }
        else if (abs(divisor_sum - n) <= 2)
        {
            cout << " almost perfect";
        }
        else
        {
            cout << " not perfect";
        }

        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}