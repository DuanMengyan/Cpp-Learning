#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��2��28�� ������
> Last edited time: 2019��2��28�� ������
> Topic:C++Primer Chapter13.3 ��������
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
#include "HasPtr2.h"



using namespace std;



//Chapter13.3
void Fun_Swap()
{
	//�뿽�����Ƴ�Ա��ͬ��swap�����Ǳ�Ҫ�ģ�
	//���ǣ����ڷ�������Դ����(��Ϊ��ֵ����)������swap������һ�ֺ���Ҫ���Ż��ֶ�

	//swap����Ӧ�õ���swap����������std::swap;
	//������������ض���swap�汾,��ƥ��̶Ȼ�����std�ж���İ汾
	//���򣬻����std�еİ汾���ٶ�����������using������

	//�ڸ�ֵ�������ʹ��swap ����������
	//�Զ��쳣��ȫ���ҿ�����ȷ�����Ը�ֵ��
	//�п��ܻ��ڿ������캯��new���ʽ���׳��쳣�����ǻ��ڸı�����������֮ǰ����
	//HasPtr& operator=(HasPtr rhs)
	//{
	//	swap(*this, rhs);
	//	return *this;
	//}

	//ex13.29
	//int��ָ�롢string�ȶ���������Ƕ�����Լ��汾��swap��HasPtr������Լ������swap(HasPtr &, HasPtr &)

	//ex13.30

	//ex13.31
	HasPtr2 a("a"); 
	HasPtr2 b("b"); 
	HasPtr2 c("c"); 
	HasPtr2 d("d");
	vector<HasPtr2> vec{a,c,b,d};
	show(vec);
	sort(vec.begin(), vec.end());
	show(vec);

	//ex13.32
	//�ӱ����Ͻ��������ڴ��������������ܵ�ԭ��
	//��ָ�����汾��ʹ�ñ������Դ���swap()�����������Ŀ�������û�ж�̬�ڴ����
	//������Ҫ�Զ���һ��swap�Խ���ָ����ָ���ֵ�����Բ���������Ч��
}




int main()
{	

	//Chapter13.3
	Fun_Swap();
	return 0;
}
