#include<stdio.h>

struct person
{
	int age;
	char name[20];
};

struct person2
{
	int* age; // 구조체 멤버로 포인터를 가지는 경우
	char name[20];
};

struct location
{
	char add[20];
	char tel[20];
};

struct work
{
	char name[20];
	int age;
	struct location* loc; //구조체 포인터를 구조체 멤버로 갖는 경우
};

struct alpha
{
	char abc;
};

typedef struct alpha abc;//typedef 를 사용하면 struct alpha abc 라고 쓰지 않고 바로 alpha abc라고 선언이 가능해짐.
//바로 typedef 와 함께 선언할 때는 아래처럼 typedef를 맨앞에, 새로 정의할 이름을 맨 뒤에 써주면 된다. 일반적으로 data와 Sdata는 동일하게 한다.
// 일반적으로 앞의 data는 생략하고 맨 뒤에만 이름을 써주면 됨. 그러나 자기참조구조체를 만들 경우에는 이름이 앞에도 써져 있어야 함.
//typedef struct data
//{
//	int data;
//}Sdata;


int main()
{
	struct person p1 = { 25,"hjy" }; // person 이라는 구조체 p1을 선언.
	printf("%s %d\n", p1.name, p1.age); // 구조체 내부는 연산자 . 으로 접근 가능.

	struct person personarr[3] = { {25,"hjy"},{25,"kdh"},{25,"ksc"} }; 
	printf("%d %s\n", personarr[0].age, personarr[2].name); //구조체 배열 선언 및 사용

	struct person* pman=&p1; // 구조체는 크기가 크기 때문에 포인터를 배정해 사용하는 것이 좋다. 구조체 포인터 = 구조체 포인터를 이용해 내부 접근 가능
	printf("%s %d\n", (*pman).name, (*pman).age); // 간접참조연산자가 . 보다 순위가 낮기 때문에 반드시 괄호를 씌워주어야 한다. 
	printf("%s %d\n", (*pman).name, pman->age); //혹은 화살표를 이용해도 됨(*.을 합쳐 ->로 표기)

	int page = 27;
	struct person2 p2 = { &page, "hjy" };
	printf("%d\n", *(p2.age)); //포인터를 가지고 있는 구조체의 사용

	struct work workplace = { "nexon",20 };
	struct location sloc = { "seoul", "2000" };
	workplace.loc = &sloc;
	printf("%s %d %s %s", workplace.name, workplace.age, workplace.loc->add, workplace.loc->tel);

	return 0;
}