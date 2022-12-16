#include <bits/stdc++.h>
#include <sstream>

using namespace std;

vector<string> splitString(string line, char separator)
{
    stringstream ss(line);
    string segment;
    vector<string> res;

    while (getline(ss, segment, separator))
        res.push_back(segment);

    return res;
}

void solvePart1(vector<int> &values)
{
    int res = 0;
    for (auto i : vector<int>{{20, 60, 100, 140, 180, 220}})
        res += i * values[i - 1];

    cout << res << '\n';
}

void solvePart2(vector<int> &values)
{
    string result;
    for (auto i = 0; i < 240; i++)
    {
        int x = i % 40;
        int spritePos = values[i];
        (spritePos - 1 <= x && x <= spritePos + 1) ? cout << '#' : cout << '.';
        if ((i + 1) % 40 == 0)
            cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<int> values;
    values.push_back(1);


    while (getline(cin, line))
    {
        values.push_back(values.back());
        if (line[0] == 'a')
        {
            auto splits = splitString(line, ' ');
            values.push_back(values.back() + stoi(splits[1]));
        }
    }

    solvePart1(values);
    solvePart2(values);

    return 0;
}
