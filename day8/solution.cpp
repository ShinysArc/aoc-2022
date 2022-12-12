#include <bits/stdc++.h>

using namespace std;

void solve(vector<string> data)
{
    size_t rows = data.size();
    size_t cols = data[0].length();
    size_t visibles = 0;
    size_t scenic = 0;

    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
        {
            bool visible = false;
            size_t score = 1;
            for (array<int, 2> direction: vector<array<int, 2>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}})
            {
                auto row = i;
                auto col = j;
                size_t dist = 0;

                while (true)
                {
                    row += direction[0];
                    col += direction[1];

                    if (row < 0 || row > rows - 1 || col < 0 || col > cols - 1)
                    {
                        visible = true;
                        break;
                    }

                    dist++;
                    if (data[row][col] >= data[i][j])
                        break;
                }

                score *= dist;
            }

            if (visible)
                visibles++;

            if (score > scenic)
                scenic = score;
        }
    }

    cout << visibles << '\n';
    cout << scenic << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<string> data;
    string line;

    while (getline(cin, line))
        data.push_back(line);

    solve(data);

    return 0;
}
