/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// ���ľ���
/// ����ÿ�����Σ��Ըþ��εĸ�Ϊ����εĸߣ�����������չ������ҳ������Ǹ�

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

        // ����
        for (int iter1 = iter - 1; iter1 >= 0; iter1--)
        {
            if (heights[iter1] < height)
            {
                break;
            }

            area += height;
        }

        // ����
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
