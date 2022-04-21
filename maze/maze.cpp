// maze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


void ShowMaze(char szMaze[][20], int iRow)
{
    for (int i = 0; i < iRow; i++) {
        puts(szMaze[i]);
    }
}

void Maze(char szMaze[][20], int iRow, int x, int y)
{
    system("cls");
    ShowMaze(szMaze, iRow);
    system("pause");

    if ('$' == szMaze[x][y]) {
        puts("OK");
        exit(0);
    }

    szMaze[x][y] = 'a';
    if ('0' == szMaze[x - 1][y] || '$' == szMaze[x - 1][y]) {
        Maze(szMaze, iRow, x - 1, y);
    }

    if ('0' == szMaze[x][y - 1] || '$' == szMaze[x][y - 1]) {
        Maze(szMaze, iRow, x, y - 1);
    }

    if ('0' == szMaze[x + 1][y] || '$' == szMaze[x + 1][y]) {
        Maze(szMaze, iRow, x + 1, y);
    }

    if ('0' == szMaze[x][y + 1] || '$' == szMaze[x][y + 1]) {
        Maze(szMaze, iRow, x, y + 1);
    }

    szMaze[x][y] = 'b';
    system("cls");
    ShowMaze(szMaze, iRow);
    system("pause");
}

int main()
{
    int iRow;
    char szMaze[][20] = {
        "1111111111111111111",
        "1011110000000010001",
        "1000110110111010101",
        "1010110110111010001",
        "1000010000111010101",
        "1011010110111010101",
        "10000000001110001$1",
        "1111111111111111111"
    };
    std::cout << "Hello Maze!\n";

    iRow = sizeof(szMaze) / sizeof(szMaze[0]);

    ShowMaze(szMaze, iRow);

    Maze(szMaze, iRow, 1, 1);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
