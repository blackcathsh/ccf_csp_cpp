/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// ISBN����
/// ����Ϊ13λISBN���룬���ʶ���������һλ���бȶԼ���

#include <iostream>
#include <string>

using namespace std;

char CalculateISBN(string& s);

int main()
{
    string s;
    
    cin >> s;

    char code = CalculateISBN(s);

    if (code == s[12])
    {
        cout << "Right";
    }
    else
    {
        s[12] = code;
        cout << s;
    }

    return 0;
}

char CalculateISBN(string& s)
{
    int multi = 1;
    int sum = 0;

    for (int iter = 0; iter < 11; iter++)
    {
        if (s[iter] != '-')
        {
            sum += multi * (s[iter] - '0');
            multi++;
        }
    }

    sum %= 11;

    if (sum == 10)
    {
        return 'X';
    }
    else
    {
        return static_cast<char>(sum + '0');
    }
}
