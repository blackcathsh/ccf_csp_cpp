/// @note   Copyright (c) 2020 huangshenghua
/// @author huangshenghua

/// 分为两部分：能从初始位置到某方格、能从某方格到目标位置
/// 使用图的搜索算法

#include <iostream>

using namespace std;

const int MaxRow = 50;
const int MaxCol = 50;

char Map[MaxRow][MaxCol];

int Rows;
int Cols;

bool StartCanReach[MaxRow][MaxCol];
bool CanReachEnd[MaxRow][MaxCol];

void DFSForward(int row, int col);
void DFSBackward(int row, int col);

int main()
{
    cin >> Rows >> Cols;

    int startRow = 0;
    int startCol = 0;
    int endRow = 0;
    int endCol = 0;

    for (int row = 0; row < Rows; row++)
    {
        for (int col = 0; col < Cols; col++)
        {
            cin >> Map[row][col];

            if (Map[row][col] == 'S')
            {
                startRow = row;
                startCol = col;
            }
            else if (Map[row][col] == 'T')
            {
                endRow = row;
                endCol = col;
            }
        }
    }

    DFSForward(startRow, startCol);

    if (!StartCanReach[endRow][endCol])
    {
        cout << "I'm stuck!";
        return 0;
    }

    DFSBackward(endRow, endCol);

    int result = 0;

    for (int row = 0; row < Rows; row++)
    {
        for (int col = 0; col < Cols; col++)
        {
            if (StartCanReach[row][col] && !CanReachEnd[row][col])
            {
                result++;
            }
        }
    }

    cout << result;

    return 0;
}

void DFSForward(int row, int col)
{
    if (Map[row][col] == '#' || StartCanReach[row][col])
    {
        return;
    }

    StartCanReach[row][col] = true;

    // 上
    if (row - 1 >= 0 && Map[row][col] != '-' && Map[row][col] != '.')
    {
        DFSForward(row - 1, col);
    }

    // 下
    if (row + 1 < Rows && Map[row][col] != '-')
    {
        DFSForward(row + 1, col);
    }

    // 左
    if (col - 1 >= 0 && Map[row][col] != '|' && Map[row][col] != '.')
    {
        DFSForward(row, col - 1);
    }

    // 右
    if (col + 1 < Cols && Map[row][col] != '|' && Map[row][col] != '.')
    {
        DFSForward(row, col + 1);
    }
}

void DFSBackward(int row, int col)
{
    if (CanReachEnd[row][col])
    {
        return;
    }

    CanReachEnd[row][col] = true;

    // 上
    if (row - 1 >= 0)
    {
        if (Map[row - 1][col] != '#' && Map[row - 1][col] != '-')
        {
            DFSBackward(row - 1, col);
        }
    }

    // 下
    if (row + 1 < Rows)
    {
        if (Map[row + 1][col] != '#' && Map[row + 1][col] != '-' && Map[row + 1][col] != '.')
        {
            DFSBackward(row + 1, col);
        }
    }

    // 左
    if (col - 1 >= 0)
    {
        if (Map[row][col - 1] != '#' && Map[row][col - 1] != '|' && Map[row][col - 1] != '.')
        {
            DFSBackward(row, col - 1);
        }
    }

    // 右
    if (col + 1 < Cols)
    {
        if (Map[row][col + 1] != '#' && Map[row][col + 1] != '|' && Map[row][col + 1] != '.')
        {
            DFSBackward(row, col + 1);
        }
    }
}
