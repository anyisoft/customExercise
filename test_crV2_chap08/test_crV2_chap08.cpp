// test_crV2_chap08.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>

/*
int main(int argc, char* argv[])
{
	char s[] = "Hello Worl";
	return 0;
}
*/
/*
int main(int argc, char* argv[])
{
	return strlen(argv[0]);
}
*/
/*
int main(int argc, char* argv[])
{
	int n1;
	int n2;
	scanf("%d%d", &n1, &n2);
	static int ary[5] = { n1, n2, 0 };

	return 0;
}
*/
/*
int main(int argc, char* argv[])
{
	int ary[4] = { 1, 2, 3, 4 };
	int n = 5;
	printf("%d", ary[-3]);

	return 0;
}
*/
int main(int argc, char* argv[])
{
	int ary[3][3][3] = { { {1, 2, 3,}, {4, 5, 6,}, {7, 8, 9,} }, { {1, 2, 3,}, {4, 5, 6,}, {7, 8, 9,} }, { {1, 2, 3,}, {4, 5, 6,}, {7, 8, 9,} } };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				printf("%d\n", ary[i][j][k]);
			}
		}
	}

	return 0;
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
