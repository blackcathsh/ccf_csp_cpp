/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// 将输入排好序后，就可以简单的左右进行匹配

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> inputs;
    inputs.reserve(n);

    int input;

    for (int iter = 0; iter < n; iter++)
    {
        cin >> input;
        inputs.push_back(input);
    }

    sort(inputs.begin(), inputs.end());

    size_t start = 0;
    size_t end = static_cast<size_t>(n) - 1;
    int count = 0;

    while (start <= end)
    {
        if (-inputs[start] > inputs[end])
        {
            ++start;
        }
        else if (-inputs[start] == inputs[end])
        {
            ++count;
            ++start;
            --end;
        }
        else
        {
            --end;
        }
    }

    cout << count;

    return 0;
}
