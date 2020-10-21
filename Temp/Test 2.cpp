#include <bits/stdc++.h> //#include<iostream>
//all the respective directories
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len = s.length();//ABC

    for (int Row_count = 0; Row_count < len; Row_count++)
    {
        //n - row_count - 1
        for (int spaces = 0; spaces < len - Row_count - 1; spaces++)
        {
            cout << " ";
        }



        //number of stars = 2*row_count + 1

        for (int stars = 0; stars < Row_count + 1; stars++)//ABC  'AB'
        {
            cout << s[stars];
        }



        for(int reverse = 0 ; reverse < Row_count ; reverse++){
            cout<<s[Row_count - reverse - 1];
        }


        cout << "\n";
    }

    return 0;
}



/*
Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Try the new cross-platform PowerShell https://aka.ms/pscore6

PS E:\Practice\Codes-Repo\Temp> cd..
PS E:\Practice\Codes-Repo> cd..
PS E:\Practice> cd .\Codes-Repo\
PS E:\Practice\Codes-Repo> cd .\Temp\
PS E:\Practice\Codes-Repo\Temp> cmd.exe
Microsoft Windows [Version 10.0.19041.572]
(c) 2020 Microsoft Corporation. All rights reserved.

E:\Practice\Codes-Repo\Temp>g++ "Test 2.cpp" -o "Test 2"     

E:\Practice\Codes-Repo\Temp>"Test 2.exe" 
ABC
  A
 ABA
ABCBA

E:\Practice\Codes-Repo\Temp>

*/