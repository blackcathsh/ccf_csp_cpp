/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// ��Ȥ����
/// ������ö�̬�滮�����
/// 
/// ��һλ�ܷ��õ�����
/// 0�������ԣ����λ���ֲ�Ϊ0��
/// 1�������ԣ����������ܳ���0���������в�����0���֣�
/// 2������
/// 3�������ԣ����������ܳ���2���������в�����2����
/// ��˵�һλֻ��Ϊ2
/// ����һ��nλ��������Ϸ�״̬�����Ϊ�����Ϸ�״̬��ָ��Υ������4��������ȫ�����֣�
/// ��4������δ��ȫ���֣�������ͨ���������ֵ�λ�������ﵽ4������ȫ���ֵ�״̬��
/// ȫ2��ֻ����20��ֻ����23��ֻ����201��ֻ����203������2013

enum NumberStateEnum
{
    State2,
    State02,
    State23,
    State012,
    State023,
    State0123,
};

/// ��nλ�������n-1λ���ֵĹ�ϵ���£�
/// count[n][State2] = count[n-1][State2]����nλ����2��
/// count[n][State02] = count[n-1][State2]����nλ����0�� + count[n-1][State02] * 2����nλ����0��2��
/// count[n][State23] = count[n-1][State2]����nλ����3�� + count[n-1][State23]����nλ����3��
/// count[n][State012] = count[n-1][State02]����nλ����1�� + count[n-1][State012] * 2����nλ����1��2��
/// count[n][State023] = count[n-1][State02]����nλ����3�� + count[n-1][State23]����nλ����0�� + count[n-1][State023] * 2����nλ����0��3��
/// count[n][State0123] = count[n-1][State012]����nλ����3�� + count[n-1][State023]����nλ����1�� + count[n-1][State0123] * 2����nλ����1��3��
/// 1λ����ʱ��״̬��
/// count[1][State2] = 1
/// count[1][State02] = 0
/// count[1][State23] = 0
/// count[1][State012] = 0
/// count[1][State023] = 0
/// count[1][State0123] = 0

class NumberCount
{
public:
    unsigned long long State2Count;
    unsigned long long State02Count;
    unsigned long long State23Count;
    unsigned long long State012Count;
    unsigned long long State023Count;
    unsigned long long State0123Count;

    NumberCount() = default;
};

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t n;
    cin >> n;

    vector<NumberCount> count(n + 1);

    count[1].State2Count = 1;

    for (size_t iter = 2; iter <= n; iter++)
    {
        count[iter].State2Count = (count[iter - 1].State2Count) % 1000000007;
        count[iter].State02Count = (count[iter - 1].State2Count + count[iter - 1].State02Count * 2) % 1000000007;
        count[iter].State23Count = (count[iter - 1].State2Count + count[iter - 1].State23Count) % 1000000007;
        count[iter].State012Count = (count[iter - 1].State02Count + count[iter - 1].State012Count * 2) % 1000000007;
        count[iter].State023Count = (count[iter - 1].State02Count + count[iter - 1].State23Count + count[iter - 1].State023Count * 2) % 1000000007;
        count[iter].State0123Count = (count[iter - 1].State012Count + count[iter - 1].State023Count + count[iter - 1].State0123Count * 2) % 1000000007;
    }

    cout << count[n].State0123Count;

    return 0;
}
