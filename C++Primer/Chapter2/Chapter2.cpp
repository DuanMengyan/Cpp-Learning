#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��07��28�� ������
> Last edited time: 2018��07��28�� ������
> Topic:C++Primer Chapter2
************************************************************************/



#include <iostream>//ϵͳͷ�ļ����ļ���Ҫ���ڼ���������������Ǹ��߱�������Ӧ�õ�����׼�ġ��ص�Ѱ������ļ���#include <stdio.h>
#include "temp.h"//�Զ���ͷ�ļ����ļ���Ҫ����˫���������

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


std::string global_str; //������
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
	int variable = 10; //�������variable
	std::cout << variable << std::endl;
}

//2.15����
void Reference()
{	
	//int ival = 1.01;   //���Ϸ��Ķ���
	//int &rval1 = 1.01;


}
int i = 42;

int main()
{

	//DataType();
	//LiteralConstant();
	//VariableInitialValue();
	//VariableDefinitionAndDeclaration();

	//Reference();


	int i = 100;
	int j = i;
	std::cout << j << std::endl;


	return 0;
}



