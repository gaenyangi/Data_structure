#include<stdio.h>

struct person
{
	int age;
	char name[20];
};

struct person2
{
	int* age; // ����ü ����� �����͸� ������ ���
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
	struct location* loc; //����ü �����͸� ����ü ����� ���� ���
};

struct alpha
{
	char abc;
};

typedef struct alpha abc;//typedef �� ����ϸ� struct alpha abc ��� ���� �ʰ� �ٷ� alpha abc��� ������ ��������.
//�ٷ� typedef �� �Բ� ������ ���� �Ʒ�ó�� typedef�� �Ǿտ�, ���� ������ �̸��� �� �ڿ� ���ָ� �ȴ�. �Ϲ������� data�� Sdata�� �����ϰ� �Ѵ�.
// �Ϲ������� ���� data�� �����ϰ� �� �ڿ��� �̸��� ���ָ� ��. �׷��� �ڱ���������ü�� ���� ��쿡�� �̸��� �տ��� ���� �־�� ��.
//typedef struct data
//{
//	int data;
//}Sdata;


int main()
{
	struct person p1 = { 25,"hjy" }; // person �̶�� ����ü p1�� ����.
	printf("%s %d\n", p1.name, p1.age); // ����ü ���δ� ������ . ���� ���� ����.

	struct person personarr[3] = { {25,"hjy"},{25,"kdh"},{25,"ksc"} }; 
	printf("%d %s\n", personarr[0].age, personarr[2].name); //����ü �迭 ���� �� ���

	struct person* pman=&p1; // ����ü�� ũ�Ⱑ ũ�� ������ �����͸� ������ ����ϴ� ���� ����. ����ü ������ = ����ü �����͸� �̿��� ���� ���� ����
	printf("%s %d\n", (*pman).name, (*pman).age); // �������������ڰ� . ���� ������ ���� ������ �ݵ�� ��ȣ�� �����־�� �Ѵ�. 
	printf("%s %d\n", (*pman).name, pman->age); //Ȥ�� ȭ��ǥ�� �̿��ص� ��(*.�� ���� ->�� ǥ��)

	int page = 27;
	struct person2 p2 = { &page, "hjy" };
	printf("%d\n", *(p2.age)); //�����͸� ������ �ִ� ����ü�� ���

	struct work workplace = { "nexon",20 };
	struct location sloc = { "seoul", "2000" };
	workplace.loc = &sloc;
	printf("%s %d %s %s", workplace.name, workplace.age, workplace.loc->add, workplace.loc->tel);

	return 0;
}