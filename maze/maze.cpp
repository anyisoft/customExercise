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

void ArrayMaze(char szMaze[][20], int iRow, int x, int y)
{
    bool bFound, bBackTrack;
    int xCur, yCur;

    int xStack[20 * 20];
    int yStack[20 * 20];

    int xTop = -1;
    int yTop = -1;

    xCur = x;
    yCur = y;

    bFound = false;
    bBackTrack = false;

    while (!bFound) {
        if ('$' == szMaze[yCur][xCur]) {
            puts("OK");
            break;
        }

        szMaze[yCur][xCur] = 'a';
        xTop++;
        xStack[xTop] = xCur;
        yTop++;
        yStack[xTop] = yCur;

        system("cls");
        ShowMaze(szMaze, iRow);
        system("pause");

        if ('0' == szMaze[yCur][xCur - 1] || '$' == szMaze[yCur][xCur - 1]) {
            xCur -= 1;
        }
        else if ('0' == szMaze[yCur - 1][xCur] || '$' == szMaze[yCur - 1][xCur]) {
            yCur -= 1;
        }
        else if ('0' == szMaze[yCur][xCur + 1] || '$' == szMaze[yCur][xCur + 1]) {
            xCur += 1;
        }
        else if ('0' == szMaze[yCur + 1][xCur] || '$' == szMaze[yCur + 1][xCur]) {
            yCur += 1;
        }
        else {
            bBackTrack = true;
            do {
                szMaze[yCur][xCur] = 'b';
                xCur = xStack[xTop];
                xTop--;
                yCur = yStack[yTop];
                yTop--;
                
                if (   '0' == szMaze[yCur][xCur - 1] || '$' == szMaze[yCur][xCur - 1]
                    || '0' == szMaze[yCur - 1][xCur] || '$' == szMaze[yCur - 1][xCur]
                    || '0' == szMaze[yCur][xCur + 1] || '$' == szMaze[yCur][xCur + 1]
                    || '0' == szMaze[yCur + 1][xCur] || '$' == szMaze[yCur + 1][xCur]) {
                    bBackTrack = false;
                }

                system("cls");
                ShowMaze(szMaze, iRow);
                system("pause");

            } while (bBackTrack);

        }
    }
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

    //Maze(szMaze, iRow, 1, 1);
    ArrayMaze(szMaze, iRow, 1, 1);
}
