/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// 每个窗口是一个矩形，有一定的优先级顺序
/// 当点击窗口时，应该从由优先级高的开始匹配，匹配成功，则将其提升为最高优先级，否则忽略本次操作
/// 
/// 使用链表来管理窗口，排序为优先级从高到低，匹配时优先级从高到低遍历匹配
/// 匹配成功时，将其从链表中删除，并加入到链表头（不使用数组是因为此步骤会有额外的移动元素的代价，使用链表插入删除元素则快一些）

#include <iostream>
#include <list>

using namespace std;

struct Window
{
    int number;

    int LeftTopX;
    int LeftTopY;
    int RightBottomX;
    int RightBottomY;

    bool Contain(int x, int y);
};

int main()
{
    int n = 0;
    int m = 0;

    cin >> n >> m;

    list<Window> windows;

    for (int iter = 0; iter < n; iter++)
    {
        Window window;
        cin >> window.LeftTopX >> window.LeftTopY >> window.RightBottomX >> window.RightBottomY;
        window.number = iter + 1;
        windows.push_front(window);
    }

    int x = 0;
    int y = 0;

    for (int iter = 0; iter < m; iter++)
    {
        cin >> x >> y;

        bool isFind = false;

        for (auto pos = windows.begin(); pos != windows.end(); ++pos)
        {
            if (pos->Contain(x, y))
            {
                isFind = true;

                cout << pos->number << endl;

                if (pos == windows.begin())
                {
                    break;
                }

                Window window = *pos;

                windows.erase(pos);
                windows.push_front(window);

                break;
            }
        }

        if (!isFind)
        {
            cout << "IGNORED" << endl;
        }
    }

    return 0;
}

/// @brief 判断点是否属于此窗口
/// @param x 点的x坐标
/// @param y 点的y坐标
/// @return
bool Window::Contain(int x, int y)
{
    return x >= LeftTopX && x <= RightBottomX && y >= LeftTopY && y <= RightBottomY;
}
