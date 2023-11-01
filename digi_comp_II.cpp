#include <bits/stdc++.h>
using namespace std;

int n;
string characters;

string getOrder()
{
    unordered_set<char> uset;
    string order = "";

    for (char c : characters)
    {
        if (uset.find(c) == uset.end())
        {
            order += c;
            uset.insert(c);
        }

        if (uset.size() == 3)
        {
            return order;
        }
    }

    return order;
}

int solve()
{
    string order = getOrder();

    if (order.size() < 3)
    {
        cout << 0;
        return 0;
    }

    int curr_index = 0, min_count = 0;
    set<char> uset;

    for (int i = 0; i < characters.size(); i++)
    {
        char c = characters[i];

        if (c == order[curr_index])
        {
            cout << "1";
            continue;
        }

        if (curr_index == 0 || curr_index == 1)
        {
            cout << "2";
            curr_index++;
            continue;
        }

        if (i == characters.size() - 1 && c == order[0])
        {
            cout << "3";
            continue;
        }

        min_count++;
        cout << c << "\n";
    }

    cout << min_count << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> characters;
    solve();

    return 0;
}