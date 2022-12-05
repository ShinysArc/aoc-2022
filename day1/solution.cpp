#include <bits/stdc++.h>

using namespace std;

void solvePartOne(map<size_t, size_t> deers)
{
    auto max = max_element(deers.begin(), deers.end(),
         [](const pair<size_t, size_t>& p1, const pair<size_t, size_t>& p2) {
         return p1.second < p2.second; });
    cout << max->second << '\n';
}

void solvePartTwo(map<size_t, size_t> deers)
{
    size_t res = 0;

    for (auto i = 0; i < 3; i++)
    {
        auto max = max_element(deers.begin(), deers.end(),
            [](const pair<size_t, size_t>& p1, const pair<size_t, size_t>& p2) {
            return p1.second < p2.second; });
        res += max->second;
        deers.erase(max->first);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<size_t, size_t> deers;
    size_t index = 1;
    string line;

    while (getline(cin, line))
    {
        if (!line.empty())
            deers[index] += stol(line);
        else
            index++;
    }

    solvePartOne(deers);
    solvePartTwo(deers);

    return 0;
}
