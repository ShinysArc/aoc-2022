#include <bits/stdc++.h>
#include <sstream>

using namespace std;

bool shouldMove(const pair<int, int> &fst, const pair<int, int> &snd)
{
    return abs(fst.first - snd.first) > 1 || abs(fst.second - snd.second) > 1;
}

int compare(const int &fst, const int &snd)
{
    return fst == snd ? 0 : (fst > snd ? 1 : -1);
}

size_t solve(vector<string> data, size_t size)
{
    vector<pair<int, int>> rope(size, make_pair(0, 0));
    unordered_set<long long> visited;
    for (auto &line : data)
    {
        char direction = line[0];
        size_t steps = stoi(line.substr(2));
        for (auto j = 0; j < steps; j++)
        {
            switch (direction)
            {
            case 'U':
                rope[0].second++;
                break;
            case 'D':
                rope[0].second--;
                break;
            case 'L':
                rope[0].first--;
                break;
            default:
                rope[0].first++;
                break;
            }

            for (auto i = 1; i < size && shouldMove(rope[i - 1], rope[i]); i++)
            {
                rope[i].second += compare(rope[i - 1].second, rope[i].second);
                rope[i].first += compare(rope[i - 1].first, rope[i].first);
            }

            visited.insert(((long long)rope.back().first * 10000 + rope.back().second));
        }
    }

    return visited.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<string> data;

    while (getline(cin, line))
        data.push_back(line);

    cout << solve(data, 2) << '\n';
    cout << solve(data, 10) << '\n';

    return 0;
}
