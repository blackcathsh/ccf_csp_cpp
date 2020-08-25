/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// ÿ��������һ�����Σ���һ�������ȼ�˳��
/// ���������ʱ��Ӧ�ô������ȼ��ߵĿ�ʼƥ�䣬ƥ��ɹ�����������Ϊ������ȼ���������Ա��β���
/// 
/// ʹ�������������ڣ�����Ϊ���ȼ��Ӹߵ��ͣ�ƥ��ʱ���ȼ��Ӹߵ��ͱ���ƥ��
/// ƥ��ɹ�ʱ�������������ɾ���������뵽����ͷ����ʹ����������Ϊ�˲�����ж�����ƶ�Ԫ�صĴ��ۣ�ʹ���������ɾ��Ԫ�����һЩ��

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

/// @brief �жϵ��Ƿ����ڴ˴���
/// @param x ���x����
/// @param y ���y����
/// @return
bool Window::Contain(int x, int y)
{
    return x >= LeftTopX && x <= RightBottomX && y >= LeftTopY && y <= RightBottomY;
}
