// test_crV2_chap10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>

class Person {
public:
	Person() {
		name = NULL;
	}

	Person(const Person& obj) {
		int len = strlen(obj.name);
		this->name = new char[len + sizeof(char)];
		strcpy(this->name, obj.name);
	}

	void setName(const char* name) {
		int len = strlen(name);
		if (this->name) {
			delete[] this->name;
		}
		this->name = new char[len + sizeof(char)];
		strcpy(this->name, name);
	}

public:
	char* name;
};

void show(Person person)
{
	printf("name:%s\n", person.name);
}

int main(int argc, char* argv[])
{
	Person person;
	person.setName("Hello");
	show(person);

	return 0;
}