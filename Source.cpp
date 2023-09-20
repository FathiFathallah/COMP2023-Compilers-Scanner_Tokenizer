#include <iostream>
#include "FileDescriptor.h"
#include "Scanner.h"
#include <cctype>

using namespace std;

int main()
{
    string str = "";
    cout << "ENTER FILE NAME: ";
    cin >> str;
    char *fileName = new char[str.length() + 1];
    strcpy(fileName, str.c_str());
    FileDescriptor *Fd = new FileDescriptor(fileName);

    TOKEN *returnedToken;
    Scanner *scanner = new Scanner(Fd);
    while (1)
    {
        returnedToken = scanner->Scan();

        if (returnedToken->type == LX_ERROR)
        {
            continue;
        }

        if (returnedToken->type == LX_WHITE_SPACE)
            continue;

        else if (returnedToken->type == 1)
        {
            cout << "TYPE: 0" << returnedToken->type << " | "
                 << "INTEGER: " << returnedToken->value << "\n";
        }

        else if (returnedToken->type == 3)
        {
            cout << "TYPE: 0" << returnedToken->type << " | "
                 << "FLOAT: " << returnedToken->float_value << "\n";
        }

        else
        {
            if (returnedToken->type >= KW_PROGRAM && returnedToken->type <= KW_END || returnedToken->type == LX_IDENTIFIER)
            {
                cout << "TYPE: " << returnedToken->type << " | ";
                cout << "LX_";
            }
            else
            {
                cout << "TYPE: " << returnedToken->type << " | ";
            }
            int i = 0;
            while (returnedToken->str_ptr[i] != '\0')
            {
                char a = (returnedToken->str_ptr[i]);
                a = std::toupper(a);
                cout << a;
                i++;
            }
            cout << "\n";
        }

        if (returnedToken->type == LX_EOF)
            break;
    }

    return 0;
}