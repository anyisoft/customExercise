// test_crV2_chap11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

class Global {
public:
	Global() {
		printf("Global\n");
	}

	Global(int n) {
		printf("Global(int n) %d\n", n);
	}

	Global(const char *s) {
		printf("Global(char *s) %s\n", s);
	}

	virtual ~Global() {
		printf("~Global()\n");
	}

	void show() {
		printf("Object Addr: 0x%p", this);
	}
};

Global g_global1;
Global g_global2(10);
Global g_global3("hello C++");

int main(int argc, char* argv[])
{
	g_global1.show();
	g_global2.show();
	g_global3.show();

	return 0;
}