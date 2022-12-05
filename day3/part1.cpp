#include <bits/stdc++.h>

using namespace std;

size_t getPriority(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	else
		return (c - 'A' + 27);
}

size_t getItemPriority(string str1, string str2)
{
    map<char, int> occur;
    for (auto i = 0; i < str1.size(); i++)
        occur[str1[i]] = 1;
    for (auto i = 0; i < str2.size(); i++) {
        if (occur[str2[i]])
            return getPriority(str2[i]);
    }

    return 0;
}

void solve(vector<pair<string, string>> rucksacks)
{
    size_t res = 0;
    for (auto& rucksack : rucksacks)
        res += getItemPriority(rucksack.first, rucksack.second);
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<pair<string, string>> rucksacks;

    while (getline(cin, line))
    {
        pair<string, string> p;
        auto mid = line.size() / 2;
        p.first = line.substr(0, mid);
        p.second = line.substr(mid, line.size());
        rucksacks.push_back(p);
    }

    solve(rucksacks);

    return 0;
}
