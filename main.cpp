#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Run(string code)
{
    int current = 499;
    vector<int> cells(1000, 0);
    vector<string> blocks;

    for (int i = 0; i < size(code); i++)
    {
        switch (code[i])
        {
        case '>':
            current++;
            break;

        case '<':
            current--;
            break;

        case '+':
            cells[current]++;
            break;

        case '-':
            cells[current]--;
            break;

        case '.':
            cout << cells[current] << " ";
            break;

        case ',':
            cin >> cells[current];
            break;

        case '[':
            if (cells[current] == 0)
                for (int tmp = i; tmp < size(code); tmp++)
                    if (code[tmp] == ']')
                        i = tmp + 1;
            break;

        case ']':
            if (cells[current] != 0)
                for (int tmp = i; tmp > 0; tmp--)
                    if (code[tmp] == '[')
                        i = tmp + 1;

            break;

        default:
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    Run("++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++");
    return 0;
}