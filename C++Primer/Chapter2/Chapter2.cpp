#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��07��28�� ������
> Last edited time: 2018��08��3�� ������
> Topic:C++Primer Chapter2
************************************************************************/



#include <iostream>//ϵͳͷ�ļ����ļ���Ҫ���ڼ���������������Ǹ��߱�������Ӧ�õ�����׼�ġ��ص�Ѱ������ļ���#include <stdio.h>
#include "Chapter2.h"//�Զ���ͷ�ļ����ļ���Ҫ����˫���������
#include <cstdlib>


using namespace std;

//2.3��������ת��
void DataType() 
{ 		
	//unsigned int u = 10;		
	//int i = -42;	
	//std::cout << i + i << std::endl;	
	//std::cout << u + i << std::endl;	
	//unsigned u1 = 42, u2 = 10;	
	//std::cout << u1 - u2 << std::endl;
	//std::cout << u2 - u1 << std::endl;
	 
	
	//for (unsigned i = 10; i >= 0; --i)  //�޷��ŵ�i��ԶҲ����С��0������д������
	//	std::cout << i << std::endl;	
	
	
	
	/*���ʽ�м��д��������������޷������ͣ�	
	����������ȡֵΪ��ʱ�������쳣�����
	��Ϊ���������������Զ�ת��Ϊ�޷�������	*/
	
	int a = -1;	unsigned b = 1;	
	std::cout << a * b << std::endl;		//aת��Ϊȡģ�޷�����4294967295�����Ϊ��4294967295
	unsigned u = 10, u2 = 42;	
	std::cout << u2 - u << std::endl;		//32	
	std::cout << u - u2 << std::endl;		//���-32�����޷������ͷ�Χ�������쳣
	int i = 10, i2 = 42;	
	std::cout << i2 - i<< std::endl;		//32	
	std::cout << i - i2 << std::endl;		//-32	
	std::cout << i- u << std::endl;			//0	
	std::cout << u - i << std::endl;		//0


}

//2.8����ֵ����
void LiteralConstant()  
{
	std::cout << "Hi \x4dO\115!\n";
	std::cout << '\115' << '\n';

	std::cout << "2\115" << std::endl;
	std::cout << '2' << '\t' << '\x4d' << std::endl;
}


std::string global_str; //�մ�
int global_int;
//2.10������ʼֵ
/*
/����ڶ������ʱû��ָ����ֵ����ô�����ᱻĬ�ϳ�ʼ����
/�������ʣ�
/1���������κκ�������ı����ᱻ��ʼ��Ϊ0��   
/2�������ں������ڲ��ı������ᱻ��ʼ���� 
/3����Ķ���δ����ʼ�������ֵ���������
*/
void VariableInitialValue()
{
	int local_int = 1;
	std::string local_str;
	std::cout << &global_str << std::endl;		
	std::cout << global_int << std::endl;
	std::cout << &local_str << std::endl;
	std::cout << local_int << std::endl;
}


//2.11���������붨��
/*
������ʹ������Ϊ������֪�������ʹ�øñ����������ʵ�ְ�����������������ȷ�����������ֺ����͡�

���壺���������ֹ�����ʵ�塣���������洢�ռ䣬���ܻḳ���ʼֵ��

���������һ�����������붨��������ô�����ڱ�����ǰ��extern�ؼ��֡�
*/
void VariableDefinitionAndDeclaration()
{
	//int variable = 10; //�������variable
	std::cout << variable << std::endl;
	
}

//2.15����(��ʵ�Ǳ����ı���)
void Reference()
{	
	//int ival = 1.01;   //���Ϸ��Ķ���
	//int i = 1;
	//int &rval1 = i;  //�ǳ������õĳ�ʼֵ����Ϊ��ֵ�����Ƕ���ı�����int i = 1��i����ֵ��1����ֵ��
	//rval1 = 2;
	//std::cout << rval1 << std::endl;
	//int &a = i;
	int i = 0, &ri = i;
	i = 5; ri = 10;
	std::cout << i << "  " << ri << std::endl;
}

//2.20ָ��
void Pointer()
{
	//int *p1 = nullptr;
	//int *p2 = 0;
	//int *p3 = NULL;
	//std::cout << p1 << std::endl;
	//std::cout << p2 << std::endl;
	//std::cout << p3 << std::endl;	
	//int *pi = 0;
	//int i = 42;
	//int *pi = &i;
	//int **ppi2 = &pi;   //˫��ָ��
	//std::cout << i << std::endl;
	//std::cout << *pi << std::endl;
	//std::cout << **ppi2 << std::endl;
	int i = 42;
	int *p;
	int *&r = p;
	r = &i;
	*r = 0;
	std::cout << i << std::endl;
}

// const�޶���
void Fun_const()
{
	//int i = 42;
	//const int &r1 = i;	
	//const int &r2 = 42;
	//const int &r3 = r1 * 2;
	////int &r4 = r1 * 2;  //�ǳ����ĳ�ʼֵ����Ϊ��ֵ��Ҳ���Ǳ����Ƿǳ�������

	//std::cout << r1 << std::endl;	//42
	//i = 45;
	//std::cout << r1 << std::endl;	//45
	//std::cout << r3 << std::endl;	//84,r3�Ƕ�r1*2����������

	//double dval = 3.14;
	//const int &ri = dval;
	//std::cout << ri << std::endl;   //3


	// ���õ����ͱ������������ö��������һ�£��������⣺
	//1.����һ���������ð󶨷ǳ�����������ֵ��������һ��һ����ʽ
	//2.

	// ָ������ͱ���������ָ�Ķ��������һ�£��������⣺
	//1.����һ��ָ������ָ��ָ��һ���ǳ�������
	//2.

	//�����const int &(��int�ͳ���������)��const int *(ָ��int�ͳ�����ָ��) 
	//����Ϊָ���˳������������Ծ��ز�ȥ�ı���ָ�����ֵ����������ָ��Ĳ���һ���ǳ�������
	//����Ҫ�����ǲ���ͨ�����ú�ָ��ı���ָ�����ֵ
	
	
	
	
	//constָ��,����ָ�룬ָ�뱾����һ��������һ����ʼ����ɡ�����ֵ����������ŵĵ�ַ���Ͳ��ܸı��ˡ�
	//���ඨ����������Ķ���������ĺ���
	int errNumb = 0;
	int *const curErr = &errNumb;   //*����constǰ˵��ָ����һ������
	const double pi = 3.14159;
	const double *const pip = &pi;
	//����ָ��curErr��pip��curErrָ��һ��int�ͱ�����pipָ�����һ��double�ͳ�����
	//������curErr�޸�errNumb��ֵ�����ǲ�����pip�޸�pi��ֵ
	std::cout << *curErr << std::endl;  //0
	*curErr = 1;
	std::cout << *curErr << std::endl;	//1
}

//2.4.2����ϰ
void const_and_pointer()
{
	//const int *p;
	//int i = 5;
	//p = &i;
	//i = 6;
	//std::cout << *p << std::endl;

	//����const������������ǳ����������޸ģ��͵ײ�const��ָ������õĶ���ʱconst���䱾������޸ģ�
	int i = 42, j = 45;
	const int *pi = &i;		//�ײ�const������ı�pi��ֵ
	pi = &j;
	std::cout << *pi << std::endl;
}


int main()
{

	//DataType();
	//LiteralConstant();
	//VariableInitialValue();
	//VariableDefinitionAndDeclaration();

	//Reference();
	//Pointer();
	//Fun_const();

	const_and_pointer();

	return 0;
}



