// test_crV2_chap12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

/*
class Person {
public:
	Person() {}
	virtual ~Person() {}
	virtual void showSpeak() {}
};

class Chinese : public Person {
public:
	Chinese() {}
	virtual ~Chinese() {}
	virtual void showSpeak() {
		printf("Speak Chinese\r\n");
	}
};

class American : public Person {
public:
	American() {}
	virtual ~American() {}
	virtual void showSpeak() {
		printf("Speak American\r\n");
	}
};

class German : public Person {
public:
	German() {}
	virtual ~German() {}
	virtual void showSpeak() {
		printf("Speak German\r\n");
	}
};

void speak(Person* person)
{
	person->showSpeak();
}

int main(int argc, char* argv[])
{
	Chinese chinese;
	American american;
	German german;

	speak(&chinese);
	speak(&american);
	speak(&german);

	return 0;
}
*/

/*
class Person {
public:
	Person() {
		showSpeak();
	}

	virtual ~Person() {
		showSpeak();
	}

	virtual void showSpeak() {
		printf("%s::showSpeak()\n", getClassName());
	}

	virtual const char* getClassName() {
		return "Person";
	}
};

class Chinese : public Person {
public:
	Chinese() {
		showSpeak();
	}

	virtual ~Chinese() {
		showSpeak();
	}


	virtual const char* getClassName() {
		return "Chinese";
	}
};

int main(int argc, char* argv[])
{
	Person* p = new Chinese;
	p->showSpeak();
	delete p;

	return 0;
}
*/

/*
#include <new.h>

class Person {
public:
	Person() {}
	virtual ~Person() {}
	virtual void showSpeak() {}
};

class Chinese : public Person {
public:
	Chinese() {}
	virtual ~Chinese() {}
	virtual void showSpeak() {
		printf("Speak Chinese\r\n");
	}
};

int main(int argc, char* argv[])
{
	Person* p = new Chinese;
	p->showSpeak();
	p->~Person();

	p = new(p)Chinese();
	delete p;
}
*/

/*
#include <iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A's constructor" << endl;
	}


	~A()
	{
		cout << "A's destructor" << endl;
	}

	void show()
	{
		cout << "num:" << num << endl;
	}

private:
	int num;
};

int main()
{
	char mem[100];
	mem[0] = 'A';
	mem[1] = '\0';
	mem[2] = '\0';
	mem[3] = '\0';
	cout << (void*)mem << endl;
	A* p = new (mem)A;
	cout << p << endl;
	p->show();
	p->~A();
	getchar();
}
*/
/*
class Sofa {
public:
	Sofa() {
		color = 2;
	}

	virtual ~Sofa() {
		printf("virtual ~Sofa()\n");
	}

	virtual int getColor() {
		return color;
	}

	virtual int sitDown() {
		return printf("Sit down and rest your legs\r\n");
	}

protected:
	int color;
};

class Bed {
public:
	Bed() {
		length = 4;
		width = 5;
	}

	virtual ~Bed() {
		printf("virtual ~Bed()\n");
	}

	virtual int getArea() {
		return length * width;
	}

	virtual int sleep() {
		return printf("got to sleep\r\n");
	}

protected:
	int length;
	int width;
};

class SofaBed : public Sofa, public Bed {
public:
	SofaBed() {
		height = 6;
	}

	virtual ~SofaBed() {
		printf("virtual ~SofaBed()\n");
	}

	virtual int sitDown() {
		return printf("Sit down on the sofa bed\r\n");
	}

	virtual int sleep() {
		return printf("go to sleep on the sofa bed\r\n");
	}

	virtual int getHeight() {
		return height;
	}

protected:
	int height;
};

int main(int argc, char* argv[])
{
	SofaBed sofabed;
	Sofa* sofa = &sofabed;
	Bed* bed = &sofabed;

	return 0;
}
*/

class Furniture {
public:
	Furniture() {
		printf("Furniture::Furniture()\n");
		price = 0;
	}

	virtual ~Furniture() {
		printf("Furniture::~Furniture()\n");
	}

	virtual int getPrice() {
		printf("Furniture::getPrice()\n");
		return price;
	}

protected:
	int price;
};

class Sofa : virtual public Furniture {
public:
	Sofa() {
		printf("Sofa::Sofa()\n");
		price = 1;
		color = 2;
	}

	virtual ~Sofa() {
		printf("Sofa::~Sofa()\n");
	}

	virtual int getColor() {
		printf("Sofa::getColor()\n");
		return color;
	}

	virtual int sitDown() {
		return printf("Sofa::sitDown()\n");
	}

protected:
	int color;
};

class Bed : virtual public Furniture {
public:
	Bed() {
		printf("Bed::Bed()\n");
		price = 3;
		length = 4;
		width = 5;
	}

	virtual ~Bed() {
		printf("Bed::~Bed()\n");
	}

	virtual int getArea() {
		printf("Bed::getArea()\n");
		return length * width;
	}

	virtual int sleep() {
		return printf("Bed::sleep()\n");
	}

protected:
	int length;
	int width;
};

class SofaBed : public Sofa, public Bed {
public:
	SofaBed() {
		printf("SofaBed::SofaBed()\n");
		height = 6;
	}

	virtual ~SofaBed() {
		printf("SofaBed::~SofaBed()\n");
	}

	virtual int sitDown() {
		return printf("SofaBed::sitDown()\n");
	}

	virtual int sleep() {
		return printf("SofaBed::sleep()\n");
	}

	virtual int getHeight() {
		printf("SofaBed::getHeight()\n");
		return height;
	}

protected:
	int height;
};

int main(int argc, char* argv[])
{
	SofaBed sofabed;
	Furniture* p1 = &sofabed;
	Sofa* p2 = &sofabed;
	Bed* p3 = &sofabed;
	printf("%p %p %p\n", p1, p2, p3);

	return 0;
}