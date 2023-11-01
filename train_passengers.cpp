#include <bits/stdc++.h>
using namespace std;

int c, n;

void solve() {
    int curr = 0, i;
    int leave, enter, wait;
    
    for (i = 0; i < n; i++) {
        cin >> leave >> enter  >> wait;

        curr -= leave;

        if (curr > c || curr < 0) {
            cout << "impossible";
            break;
        }

        curr += enter;
        
        if (curr > c || curr < 0) {
            cout << "impossible";
            break;
        }

        if (wait > 0 && wait + curr < c) {
            cout << "impossible";
            break;
        }
    }

    if (i == n) {
        if (curr == 0 && wait == 0) {
            cout << "possible";
        }
        else {
            cout << "impossible";
        }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> c >> n;
  solve();

  return 0;
}