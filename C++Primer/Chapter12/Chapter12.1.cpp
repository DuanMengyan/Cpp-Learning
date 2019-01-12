#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��10�� ������
> Last edited time: 2019��1��12�� ������
> Topic:C++Primer Chapter12.1 ��̬�ڴ�������ָ��
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"

using namespace std;

//Chapter12.1 ��̬�ڴ�������ָ��
//Dynamic_Memory_and_Smart_Pointers


shared_ptr<int> factory(int i)
{
	return make_shared<int>(i);
}

shared_ptr<int> factory2(int i)
{
	shared_ptr<int> p = factory(i);
	return p;
}//p�뿪�������ڣ�����ָ����ڴ治�ᱻ�ͷŵ�


//12.1.1 shared_ptr��
void Fun_The_shared_ptr_Class()
{
	//shared_ptr<string> p1;
	//shared_ptr<list<int>> p2;
	//string str = "HI";
	//if (p1 && p1->empty())
	//{
	//	*p1 = str;
	//}


	//make_shares����,��ȫ��ʹ�úͷ��䶯̬�ڴ�
	//�˺����ڶ�̬�ڴ��з���һ�����󲢳�ʼ����������ָ��˶����shared_ptr��
	//shared_ptr<int> p3 = make_shared<int>(42);
	//shared_ptr<string> p4 = make_shared<string>(10, '9');
	//cout << p3 << "   " << *p3 << endl;
	//shared_ptr<int> p5 = make_shared<int>();
	//cout << p5 << "   " << *p5 << endl;
	//vector<string> vec{ "C++","hello" };
	//auto p6 = make_shared<vector<string>>(vec);
	//cout << p6 << "   " << *((*p6).begin()) << endl;
	
	//shared_ptr�Ŀ����͸�ֵ
	//auto p = make_shared<int>(42);
	//auto q(p);
	//cout << *q << endl;
	//cout << p.use_count() << endl;			//2,������p������������ָ������,���ü���
	////һ��һ��shared_ptr�ļ�������Ϊ0�����ͻ��Զ��ͷ��Լ�������Ķ���
	//auto r = make_shared<int>(50);
	//cout << r.use_count() << endl;			//1����ʱֻ��rָ�����ڶ�̬�ڴ��з����int 50
	//r = q;									//r������һ����ֵ��ԭ����int50�Զ�������
	//cout << p.use_count() << endl;			//3��q��ֵ����r�����ü���+1
	//cout << r.use_count() << endl;			//3��r��p��q��ָ��int 42�����ü���Ϊ3

	//shared_ptr�Զ�����������Ķ���
	//�����������ƴ����Ͷ�������ʱ��ʲô��������������һ�������ͷŶ������������Դ
	
	//shared_ptr�����Զ��ͷ���������ڴ�

	//auto q = factory2(42);
	//cout << q << "  " << *q << "  " << q.use_count() << endl;
	//�����shared_ptr�����һ�������У�����������������Ӷ�������ҪĳЩԪ�ء�
	//����������£�Ӧ��ȷ����eraseɾ����Щ������Ҫ��shared_ptrԪ�ء�
	
	//ʹ���˶�̬�����ڵ���Դ���ࡣ
	//����ʹ�ö�̬�ڴ��ԭ��
	//1.����֪���Լ���Ҫʹ�ö��ٶ���
	//2.����֪����������׼ȷ���ͣ�
	//3.������Ҫ�ڶ������乲�����ݣ�
	//vector<string> v1;
	//{
	//	//��������
	//	vector<string> v2 = { "a","an","the" };
	//	v1 = v2;
	//}
	//printitem(v1);
	
	//ʹ�ö�̬�ڴ��һ������ԭ������������������ͬ��״̬
	
	//����StrBlob��
	//Ԫ�ط��ʳ�Ա����
	//StrBlob�Ŀ�������ֵ������


}



int main()
{
	//12.1.1 shared_ptr��
	Fun_The_shared_ptr_Class();

	return 0;
}