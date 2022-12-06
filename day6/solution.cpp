#include <bits/stdc++.h>

using namespace std;

void solve(string buffer, size_t markerSize)
{
    auto start = begin(buffer);
    auto end = begin(buffer) + markerSize;
    for (size_t i = markerSize; i < buffer.length(); i++)
    {
        set<char> charSet{start, end};
        if (charSet.size() == markerSize)
        {
            cout << i << '\n';
            break;
        }

        start++;
        end++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    cin >> line;

    solve(line, 4);
    solve(line, 14);

    return 0;
}
