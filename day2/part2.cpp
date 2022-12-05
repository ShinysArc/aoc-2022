#include <bits/stdc++.h>

using namespace std;

enum Shape : int {
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

enum Condition : int {
    Lose = 1,
    Draw = 2,
    Win = 3
};

class Match {
public:
    Shape left;
    Shape right;
    Condition condition;

    void choose(void)
    {
        switch (condition)
        {
        case Lose:
            if (left == Rock)
                right = Scissors;
            else if (left == Scissors)
                right = Paper;
            else if (left == Paper)
                right = Rock;
            break;
        case Draw:
            right = left;
            break;
        case Win:
            if (left == Rock)
                right = Paper;
            else if (left == Scissors)
                right = Rock;
            else if (left == Paper)
                right = Scissors;
            break;
        default:
            break;
        }
    }

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
        m.condition = static_cast<Condition>(Lose + line[2] - 'X');
        m.choose();
        matches.push_back(m);
    }

    solve(matches);

    return 0;
}
