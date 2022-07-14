// test_crV2_chap04.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#pragma warning(disable : 4996)

#include <stdio.h>
/*
int main(int argc, char *argv[])
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    //scanf_s("%d %d", &n1, &n2);
    printf("%d\n", argc ? n1 : n2);
    return 0;
}
*/

void main(int argc, char* argv[], char* envp)
{
    printf("now argv[1]:%s\n", argv[1]);
    
    argv[1][0] |= argc - 1;
    argv[1][1] ^= argc - 1;
    argv[1][2]  = argv[1][2] * (argc - 1)*6;
    argv[1][3]  = argv[1][2] / 4;
    argv[1][4] =  argv[1][4] << 3;
    argv[1][5] =  argv[1][5] >> 2;
    argv[1][6] =  argv[1][6] & ((argc - 1) & 7);
    argv[1][7] %= 2;
    argv[1][8] = ~(argc - 1);

    char* pArgv9 = &argv[1][9];

    *pArgv9 = *pArgv9 + argv[1][0] - argv[1][2];

    pArgv9 += 1;

    pArgv9 += 1;

    *(pArgv9 - 1) = argv[1][6] / argv[1][7];
    *pArgv9 += argv[1][3] - argv[1][1];
    *(short*)pArgv9 = argv[1][4] * argv[1][5];

    printf("now argv[1]:%s\n", argv[1]);
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
