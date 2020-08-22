/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// 有趣的数
/// 本题采用动态规划来解决
/// 
/// 第一位能放置的数：
/// 0：不可以（最高位数字不为0）
/// 1：不可以（后续将不能出现0，即数字中不会有0出现）
/// 2：可以
/// 3：不可以（后续将不能出现2，即数字中不会有2出现
/// 因此第一位只能为2
/// 对于一个n位的数，其合法状态则可以为：（合法状态是指不违反规则，4个数字已全部出现；
/// 或4个数字未完全出现，但可以通过增加数字的位数，来达到4个数字全出现的状态）
/// 全2、只出现20、只出现23、只出现201、只出现203、出现2013

enum NumberStateEnum
{
    State2,
    State02,
    State23,
    State012,
    State023,
    State0123,
};

/// 第n位数字与第n-1位数字的关系如下：
/// count[n][State2] = count[n-1][State2]（第n位放置2）
/// count[n][State02] = count[n-1][State2]（第n位放置0） + count[n-1][State02] * 2（第n位放置0或2）
/// count[n][State23] = count[n-1][State2]（第n位放置3） + count[n-1][State23]（第n位放置3）
/// count[n][State012] = count[n-1][State02]（第n位放置1） + count[n-1][State012] * 2（第n位放置1或2）
/// count[n][State023] = count[n-1][State02]（第n位放置3） + count[n-1][State23]（第n位放置0） + count[n-1][State023] * 2（第n位放置0或3）
/// count[n][State0123] = count[n-1][State012]（第n位放置3） + count[n-1][State023]（第n位放置1） + count[n-1][State0123] * 2（第n位放置1或3）
/// 1位数字时的状态：
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
