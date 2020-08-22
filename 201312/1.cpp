/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// ���ִ���������
/// ��¼���е����ֳ��ֵĴ��������Ѱ�ҳ�������������

#include <iostream>
#include <vector>

using namespace std;

const int MaxNumber = 10000;

int main()
{
    vector<int> counts(MaxNumber + 1, 0);

    int n;
    cin >> n;

    int number;

    for (int iter = 0; iter < n; iter++)
    {
        cin >> number;
        counts[number]++;
    }

    int maxCount = 0;
    int maxCountNumber = 0;

    for (int iter = 1; iter <= MaxNumber; iter++)
    {
        if (counts[iter] > maxCount)
        {
            maxCount = counts[iter];
            maxCountNumber = iter;
        }
    }

    cout << maxCountNumber;

    return 0;
}
