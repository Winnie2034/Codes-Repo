#include <bits/stdc++.h>
#include<string.h>
using namespace std;

void encryption()
{
    std::string ans = "enc";

}

void decryption()
{
    string ans = "dec";
}

int main()
{
    bool select = true;
    // string ans = "yo";
    while (select)
    {
        int selection;
        cout << "Please enter your choice: \n\n"
             << "1. Encrypt Message \n\n"
             << "2. Decrypt Message \n\n"
             << "3. Exit\n\n";
        cin >> selection;
        switch (selection)
        {
        case 1:
            encryption();
            break;
        case 2:
            decryption();
            break;
        case 3:
            exit(0);

        default:
            cout<<"Please enter the valid number!! \n\n";
        }


        cout << "do you wish to continue? \n";
        cin >> select;
    }

    return 0;
}