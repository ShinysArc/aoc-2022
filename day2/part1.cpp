#include <bits/stdc++.h>

using namespace std;

enum Shape : int {
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

class Match {
public:
    Shape left;
    Shape right;

    size_t getShapePoints(void)
    {
        return static_cast<size_t>(right);
    }

    bool win(Shape left, Shape right)
    {
        return (left == Rock && right == Paper)
			|| (left == Paper && right == Scissors)
			|| (left == Scissors && right == Rock);
    }

    size_t getMatchPoints(void)
    {
        if (left == right)
            return 3;
        if (win(left, right))
            return 6;
        return 0;
    }

    size_t getPoints(void)
    {
        return getShapePoints() + getMatchPoints();
    }
};

void solve(vector<Match> matches)
{
    size_t res = 0;
    for (auto& match : matches)
        res += match.getPoints();

    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<Match> matches;
    string line;

    while (getline(cin, line))
    {
        Match m;
        m.left = static_cast<Shape>(Rock + line[0] - 'A');
        m.right = static_cast<Shape>(Rock + line[2] - 'X');
        matches.push_back(m);
    }

    solve(matches);

    return 0;
}
