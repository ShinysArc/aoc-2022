#include <bits/stdc++.h>

using namespace std;

class Range {
public:
    int lower;
    int higher;

    bool contains(const Range& r) const
    {
        return (lower <= r.lower && higher >= r.higher);
    }

    bool overlaps(const Range& r) const
    {
        return ((r.higher >= lower && r.lower <= higher)
                || (r.higher >= lower && r.higher <= higher));
    }
};

class Pair
{
public:
    Range left;
    Range right;
};

void solve(vector<Pair> pairs)
{
    size_t contained = 0;
    size_t overlapped = 0;
    for (auto& pair : pairs)
    {
        if (pair.left.contains(pair.right) || pair.right.contains(pair.left))
            contained++;
        if (pair.left.overlaps(pair.right) || pair.right.overlaps(pair.left))
            overlapped++;
    }

    cout << contained << '\n';
    cout << overlapped << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<Pair> pairs;

    while (getline(cin, line))
    {
        string left = line.substr(0, line.find(','));
        string right = line.substr(line.find(',') + 1, line.size());

        Pair pair;
        pair.left.lower = stoi(left.substr(0, left.find('-')));
        pair.left.higher = stoi(left.substr(left.find('-') + 1, left.length()));
		pair.right.lower = stoi(right.substr(0, right.find('-')));
		pair.right.higher = stoi(right.substr(right.find('-') + 1, right.length()));
		pairs.push_back(pair);
    }

    solve(pairs);

    return 0;
}
