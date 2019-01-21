#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��10�� ������
> Last edited time: 2019��1��21�� ����һ
> Topic:C++Primer Chapter12.1 ��̬�ڴ�������ָ��
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"

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
	
	//ʹ�ö�̬�ڴ��һ������ԭ������������������ͬ��״̬
	
	//����StrBlob��
	//Ԫ�ط��ʳ�Ա����
	//StrBlob�Ŀ�������ֵ������

	//ex12.
	//StrBlob b1;
	//{
	//	StrBlob b2 = { "a","an","the" };
	//	b1 = b2;
	//	b2.push_back("about");
	//}
	//cout << b1.size() << endl;  //4��b2��������

	//ex12.2
	//��

	//ex12.3
	//���ԣ�����û�б�Ҫ��StrBlobֻ��һ��ָ�룬��Ϊpush_back��pop_back�����޸����ݣ������޸�����ָ���vector<string>;

	//ex12.4
	//��Ϊi��vector<string>::size_type���ͣ���unsigned����iС��0ʱ�����Զ�ת���ɴ���0����	

	//ex12.5
	//StrBlob item2 = { "C++","hello","primer","python" };
	//���캯��ֻ��ֱ�ӳ�ʼ��������ʹ�����濽����ʽ�ĳ�ʼ������
}


//ex12.6
vector<int> *fun1()
{
	vector<int> *p_vec = new vector<int>;
	return p_vec;
}

vector<int> fun2(vector<int>*p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return *p_vec;
}

void fun_print(vector<int> vec)
{
	printitem(vec);
}

//ex12.7
using Sptr = shared_ptr<vector<int>>;

Sptr fun3()
{
	Sptr p_vec = make_shared<vector<int>>() ;
	return p_vec;
}

Sptr fun4(Sptr p_vec)
{
	int num;
	ifstream input("Text1.txt");
	while (input >> num)
	{
		p_vec->push_back(num);
	}
	return p_vec;
}

void fun_print2(Sptr p_vec)
{
	printitem(*p_vec);
}



//12.1.2 ֱ�ӹ����ڴ�
void Fun_Managing_Memory_Directly()
{
	//�����new�����ڴ棬delete�ͷ�new������ڴ�
	//ʹ��new��̬����ͳ�ʼ������
	//���ɿռ������ڴ��������ģ�new����һ��ָ��ö����ָ�롣
	
	//int *pi = new int;						//*piδ����
	//string *ps = new string(10, '9');		//ֵ��ʼ��
	//ֵ��ʼ�����������Ͷ����������ö����ֵ����Ĭ�ϳ�ʼ���Ķ����ֵ����δ�����
	//���������ڱ������ϳɵ�Ĭ�Ϲ��캯�����������ͳ�Ա���������δ�����ڱ���ʼ������ô���ǵ�ֵҲ��δ����ġ�
	//�������н��е�һ��ʼ����ʱ�ſ���ʹ��auto

	//��̬����const����
	//һ����̬�����const���������г�ʼ��
	//const int *pci = new const int(1024);
	//cout << *pci << endl;
	//const string *pcs = new const string("hello world!");
	//cout << *pcs << endl;

	//�ڴ�ľ�
	//��λnew���ʽ����������new���ݶ���Ĳ�����
	//int *p2 = new (nothrow) int;			//����ڴ����ʧ�ܣ�new����һ����ָ��
	
	//�ͷŶ�̬�ڴ�
	//����ͨ��delete���ʽ������̬�ڴ�黹��ϵͳ��
	//delete���ʽ����һ��ָ�룬ָ��������Ҫ�ͷŵĶ���
	//���ٶ����ͷ��ڴ�

	//ָ��ֵ��delete
	//���ݸ�delete��ָ�����ָ��̬������ڴ棬������һ����ָ�롣
	//�ͷ�һ���new������ڴ棬���߽���ͬ��ָ��ֵ�ͷŶ�Σ�����Ϊ��δ����ġ�
	//int i, *pi1 = &i, *pi2 = nullptr;
	//double *pd = new double(33), *pd2 = pd;
	//cout << *pd2 << endl;	
	//delete pd;
	//cout << *pd2 << endl;  //�쳣ֵ(����33)

	//��̬�����������ֱ�����ͷ�ʱΪֹ
	//������ָ��(����������ָ��)����Ķ�̬�ڴ��ڱ���ʾ�ͷ�ǰһֱ�������
	
	//��̬�ڴ�Ĺ���ǳ����׳������Ҫ���ʹ������ָ�롣
	//1.����delete�ڴ棻
	//2.ʹ���Ѿ��ͷŵ��Ķ���
	//3.ͬһ���ڴ��ͷ�����

	//delete֮������ָ��ֵ
	//������deleteֻ�н�nullptr����ָ�룬��ʾָ�벻ָ���κζ���
	//��ʵ��ϵͳ�У�����ָ����ͬ�ڴ������ָ�����쳣���ѵ�

	//ex12.6
	//vector<int> *temp_vec = fun1();
	//fun_print(fun2(temp_vec));
	//delete temp_vec;

	//ex12.7
	//Sptr temp_vec = fun3();
	//fun_print2(fun4(temp_vec));
	
	//ex12.8
	//p��ת��Ϊbool�ͣ���̬������ڴ潫�޷��ͷţ����ջ�����ڴ�й©
	
	//ex12.9
	//int *q = new int(42), *r = new int(100);
	//r = q;		//�ڴ�й©rָ��̬�ڴ��е�42������100���ڴ滹δ���ͷţ���Ҫdelete r�����������ڴ�й©;
	//cout << *r << endl;		
	//auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
	//r2 = q2;	//��ȫ�����һ��ָ��̬�ڴ���100������ָ��r2ָ��42������100���ڴ汻�Զ��ͷţ�
	//cout << *r2 << endl;


}


int main()
{
	//12.1.1 shared_ptr��
	//Fun_The_shared_ptr_Class();
	//12.1.2 ֱ�ӹ����ڴ�
	Fun_Managing_Memory_Directly();
	return 0;
}