#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��11�� ������
> Last edited time: 2018��10��12�� ������
> Topic:C++Primer Chapter7.4 ��������� 
************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <cctype>
#include <stdexcept>
#include <initializer_list>
#include <ctime>

using namespace std;

//7.4���������
void Fun_Class_Scope()
{
	//ex7.33
	//��Chapter7.3
}

//�������Ա���������ֲ���
typedef double Money;
string bal;
class Accont
{
public:
	Money balance(){ return bal; }  
	//return bal��������ɼ�֮���ִ�У�bal��������Money;
private:
	Money bal;
};


//��Ա�����е���ͨ������������ֲ���
//int height ;
//class Screen
//{
//public:
//	typedef std::string::size_type pos;
//	void dumy_fcn(pos height)
//	{	
//		//��ʽ��ͨ��������������������������������е�����
//		//cursor = width*::height;    
//		//cursor = width * this->height;
//
//		cursor = width*Screen::height;
//		cout << "height:" << height << endl;
//	}
//private:
//	pos cursor = 0;
//	pos height = 0, width = 0;
//
//};

//���ļ������ֵĳ��ִ�������н���
//int height;
//
//class Screen
//{
//public:
//	typedef std::string::size_type pos;
//	void setHeight(pos);
//	pos height = 0;
//};
//
//Screen::pos verify(Screen::pos);
//
//void Screen::setHeight(pos var)
//{
//	height = verify(var);
//}

//ex7.35
typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal()
	{
		return 5.0;
	}
private:
	Type val;
};

Exercise::Type Exercise::setVal(Type parm)
{
	val = parm + initVal();
	return val;
}



//7.4.1 ���ֲ��������������
void Fun_Name_Lookup_and_Class_Scope()
{
	//���������������е�ȫ��������Żᴦ���Ա�����Ķ���

	//�������Ա���������ֲ���

	//������Ҫ���⴦��
	//�������Ķ���ͨ����������Ŀ�ʼ��������ȷ������ʹ�ø����͵ĳ�Ա���������������Ķ���֮��

	//��Ա�����е���ͨ������������ֲ���

	//��������֮������Χ���������в���

	//���ļ������ֵĳ��ִ�������н���

	//ex7.34


	//ex7.35
	Exercise ex1;
	cout << ex1.setVal(5.0) << endl;
}



//
//int main()
//{
//	//7.4���������
//	//Fun_Class_Scope();
//	//7.4.1 ���ֲ��������������
//	Fun_Name_Lookup_and_Class_Scope();
//	return 0;
//}