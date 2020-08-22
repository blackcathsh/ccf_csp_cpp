/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// 最大的矩形
/// 遍历每个矩形，以该矩形的高为大矩形的高，向左向右扩展，最后找出最大的那个

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);

    for (auto& height : heights)
    {
        cin >> height;
    }

    int maxArea = 0;

    for (int iter = 0; iter < n; iter++)
    {
        int height = heights[iter];
        int area = height;

        // 向左
        for (int iter1 = iter - 1; iter1 >= 0; iter1--)
        {
            if (heights[iter1] < height)
            {
                break;
            }

            area += height;
        }

        // 向右
        for (int iter1 = iter + 1; iter1 < n; iter1++)
        {
            if (heights[iter1] < height)
            {
                break;
            }

            area += height;
        }

        maxArea = max(area, maxArea);
    }

    cout << maxArea;

    return 0;
}
