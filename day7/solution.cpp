#include <bits/stdc++.h>
#include <sstream>

using namespace std;

class Node
{
public:
    string name;
    int size = -1;
    Node *parent;
    unordered_map<string, Node*> children;
    bool dir = true;
};

array<string, 3> parseLine(string line)
{
    array<string, 3> res;
    if (line[0] == '$')
    {
        res[0] = line[0];
        line.erase(line.begin(), line.begin() + 2);
    }

    stringstream ss(line);
    ss >> res[1];
    ss >> res[2];

    return res;
}

int computeSizes(Node* current)
{
    if (current->dir)
    {
        current->size = 0;
        for (auto &child : current->children)
            current->size += computeSizes(child.second);
        return current->size;
    }
    else
        return current->size;
}

int solvePart1(Node* node)
{
    if (node->dir)
    {
        int res = 0;
        if (node->size <= 100000)
            res = node->size;

        for (auto& child : node->children)
            res += solvePart1(child.second);

        return res;
    }
    else
        return 0;
}

int solvePart2(Node* node, int size)
{
    int smallest = node->size;
    for (auto& child : node->children)
    {
        int current = solvePart2(child.second, size);
        if (child.second->dir && current >= size && current < smallest)
            smallest = current;
    }

    return smallest;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string line;
    Node* root = new Node;
    Node* current = root;
    root->name = "/";
    getline(cin, line);
    array<string, 3> command;

    while (getline(cin, line))
    {
        command = parseLine(line);
        if (command[1] == "ls")
        {
            while (getline(cin, line))
            {
                command = parseLine(line);
                if (command[0] == "$")
                    break;
                Node* newNode = new Node;
                newNode->parent = current;
                newNode->name = command[2];
                if (command[1] != "dir")
                {
                    newNode->size = stoi(command[1]);
                    newNode->dir = false;
                }

                pair<string, Node*> child;
                child.first = command[2];
                child.second = newNode;
                current->children.insert(child);
            }
        }
        if (command[1] == "cd")
        {
            if (command[2] == "/")
                current = root;
            else if (command[2] == "..")
                current = current->parent;
            else
                current = current->children.at(command[2]);
        }
    }

    computeSizes(root);
    cout << solvePart1(root) << '\n';
    int size = 30000000 - 70000000 + root->size;
    cout << solvePart2(root, size) << '\n';

    return 0;
}
