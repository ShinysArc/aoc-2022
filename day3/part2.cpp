#include <bits/stdc++.h>

using namespace std;

size_t getPriority(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a' + 1);
    else
        return (c - 'A' + 27);
}

size_t getBadgePriority(vector<string> group)
{
    vector<set<char>> sets;
    for (auto& rucksack : group)
    {
        set<char> s;
        for (auto& c : rucksack)
            s.insert(c);
        sets.push_back(s);
    }

    for (auto& c : sets[0])
    {
        if (sets[1].find(c) != sets[1].end() && sets[2].find(c) != sets[2].end())
            return getPriority(c);
    }

    return 0;
}

void solve(vector<vector<string>> rucksacks)
{
    size_t res = 0;
    for (auto& group : rucksacks)
        res += getBadgePriority(group);

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<vector<string>> rucksacks;
    vector<string> rucksack;
    size_t group = 0;

    while (getline(cin, line))
    {
        rucksack.push_back(line);
        group++;

        if (group % 3 == 0)
        {
            group = 0;
            rucksacks.push_back(rucksack);
            rucksack.clear();
        }
    }

    solve(rucksacks);

    return 0;
}
