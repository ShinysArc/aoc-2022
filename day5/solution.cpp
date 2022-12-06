#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class Instruction
{
public:
    Instruction(size_t amount, stack<char>& from, stack<char>& to)
		: amount(amount),
          from(from),
          to(to)
    {};

    size_t amount;
    stack<char>& from;
    stack<char>& to;


    void executePart1(void)
    {
        while (amount--)
        {
            to.push(from.top());
            from.pop();
        }
    }

    void executePart2(void)
    {
        stack<char> tmp;
        while (amount--)
        {
            tmp.push(from.top());
            from.pop();
        }
        while (!tmp.empty())
        {
            to.push(tmp.top());
            tmp.pop();
        }
    }
};

vector<stack<char>> parseStacks(vector<string> data)
{
    auto ground = data.begin();
	for (auto it = data.begin(); !it->empty(); it++)
		ground = it;

    size_t offset = (*ground).find_last_of("0123456789");
    string next((*ground).substr(offset));
    stringstream ss(next); size_t total;
    ss >> total;

    vector<stack<char>> stacks(total);
	ground--;

    while (true)
    {
        size_t idx = 0;
        for (size_t i = 1; i < ground->size(); i += 4)
        {
			char value = ground->at(i);
			if (value != ' ')
                stacks[idx].push(value);
            idx++;
		}

		if (ground != data.begin())
			ground--;
		else
			break;	
	}

    return stacks;
}

vector<Instruction> parseInstructions(vector<string> data, vector<stack<char>>& stacks)
{
    vector<Instruction> instructions;
    auto instructionStart = data.begin();
    while (!instructionStart->empty())
        instructionStart++;

    for (auto it = instructionStart + 1; it != data.end(); it++)
    {
        if (it->empty())
            break;

        string am_d, f_d, t_d;

        size_t amount;
        size_t from;
        size_t to;
        istringstream iss{*it};

        iss >> am_d >> amount
		    >> f_d >> from
		    >> t_d >> to;

        instructions.push_back(Instruction(amount, stacks[from - 1], stacks[to - 1]));
	}

    return instructions;
}

void solve(vector<stack<char>>& stacks, vector<Instruction>& instructions)
{
    for (auto& i : instructions)
        i.executePart2();

    for (auto& s : stacks)
        cout << s.top();
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    vector<string> data;

    while (getline(cin, line))
        data.push_back(line);

    vector<stack<char>> stacks = parseStacks(data);
    vector<Instruction> instructions = parseInstructions(data, stacks);
    solve(stacks, instructions);

    return 0;
}
