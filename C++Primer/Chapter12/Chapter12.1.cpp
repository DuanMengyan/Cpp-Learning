#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter12.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��1��10�� ������
> Last edited time: 2019��1��22�� ���ڶ�
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

void process(shared_ptr<int> ptr)
{
	cout << "=========" << endl;
	cout << ptr.use_count() << endl;	//�����ʱptr�����ü���
	cout << "process:" << *ptr << endl;
	cout << "=========" << endl;
}

//12.1.3 shared_ptr��new���ʹ��
void Fun_Using_shared_ptrs_with_new()
{
	//��new���ص�ָ������ʼ������ָ��
	//����ָ�����������ָ�빹�캯����explicit�ģ����ܽ�һ������ָ����ʽת��Ϊһ������ָ�룬��˱���ʹ��ֱ�ӳ�ʼ��
	//һ������shared_ptr�ĺ����������䷵���������ʽת��һ����ָͨ��
	//shared_ptr<int> p2(new int(42));	
	//cout << *p2 << endl;
	
	//��Ҫ���ʹ����ָͨ�������ָ��
	//����һ��shared_ptr�󶨵�һ����ָͨ��ʱ�����Ǿͽ��ڴ�Ĺ������ν��������shared_ptr��
	//�����Ͳ�Ӧ����ʹ������ָ��������shared_ptrָ����ڴ��ˡ�
	//shared_ptr<int> p(new int(42));
	//cout << p.use_count() << endl;			//1
	//process(p);
	//cout << p.use_count() << endl;			//1
	//int i = *p;			



	//int *x(new int(1024));
	////��ָͨ��x��ʾת��Ϊshared_ptr����ָ�룬���ݸ�process�����ü���Ϊ1
	////process��������ʱ�������٣����ü�����Ϊ0����ָ��ı�����1024�Ķ�̬�ڴ汻�ͷ�
	////������ָͨ��x��Ȼָ���Ѿ����ͷŵģ��ڴ棬���һ������ָ�롣
	//process(shared_ptr<int>(x));
	//int j = *x;				//ʹ��x��ֵ����Ϊδ����
	//cout << j << endl;


	//��Ҫʹ��get��ʼ����һ������ָ���Ϊ����ָ�븳ֵ
	
	//shared_ptr<int> p(new int(42));
	//cout << p.use_count() << endl;
	//int *q = p.get();
	//{
	//	shared_ptr<int>(q);
	//}
	//cout << p.use_count() << endl;
	//int foo = *p;				//δ���壬p��һ������ָ��
	//cout << foo << endl;

	//����shared_ptr����
	//��reset����һ���µ�ָ�븳��һ��shared_ptr
	//reset��uiqueһ��ʹ�ã��������ƶ��shared_ptr����Ķ���
	//shared_ptr<int> p(new int(42));
	//auto p2 = p;
	//cout << *p << "   " << p.use_count() << endl;			// 42   2
	//cout << *p2 << "   " << p.use_count() << endl;			// 42   2    
	//if (!p.unique())
	//{
	//	p.reset(new int(1024));			//pָ��һ���µĶ���	
	//}	
	//cout << *p << "   " << p.use_count() << endl;			// 1024  1
	//cout << *p2 << "   " << p.use_count() << endl;			// 42    1
	
	/*=============================================
	�����������������ڴ���ͷ�֮��Ĺ�ϵ��
	�������͵�ָ�����뿪������ʱ������ᱻ���٣�������ָ����ڴ�ռ�ʲô�����ᷢ������������ʽ��delete�����ͷſռ䡣
	����ָ�����뿪������ʱ������Ҳ�ᱻ���٣����Ҽ�������һ�����������Ϊ0��ֻ��һ������ָ��ָ��ö���ʱ���ö�����ڴ�ռ�ᱻ�ͷš�
	����������ָ���get()�����õ���һ������ָ������ʼ��һ����ʱ������ָ�룬
	һ��������ָ�뱻�ͷţ�ָ����ڴ�Ҳ�ᱻ�ͷţ�ԭ��������ָ��ͻ��ɿ�ָ��
	=============================================*/


	//ex12.10
	//shared_ptr<int> p(new int(42));
	//process(shared_ptr<int>(p));
	//cout << p.use_count() << endl;			//1


	//ex12.11
	//p���һ������ָ�룬����������������һ���ͷ��ڴ棬���˫���ͷ�
	//shared_ptr<int> p(new int(42));
	//process(shared_ptr<int>(p.get()));
	
	//ex12.12
	//auto p = new int();
	//auto sp = make_shared<int>();		//Ĭ�ϳ�ʼ��0
	//process(sp);
	//process(new int());				//��������������ָ��
	//process(p);						//ͬ��
	//process(shared_ptr<int>(sp));
	//cout << sp.use_count() << endl;


	//ex12.13
	//auto sp = make_shared<int>();
	//auto p = sp.get();
	//delete p;					//Ĭ�ϳ�ʼ��Ϊ0�Ķ�̬�ڴ汻�ͷŵ���sp���һ������ָ�룬����

}

struct connection
{
	//��ʾʹ�������������Ϣ
	string ip;
	int port;
	connection(string ip_, int port_) :ip(ip_), port(port_) {}
};

struct destination
{
	//��ʾ��������ʲô
	string ip;
	int port;
	destination(string ip_, int port_) :ip(ip_), port(port_) {}
};

connection connect(destination *pDest)
{	//������
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection...(" << pConn.use_count() << ")" << endl;
	return *pConn;
}

void disconnect(connection pConn) 
{
	//�رո�������
	cout << "connect close...(" << pConn.ip << " : " << pConn.port << ")" << endl;
}

void end_connection(connection *pConn)
{
	disconnect(*pConn);
}

void f(destination &d /* �������� */)
{
	//���һ�����ӣ���סʹ�����Ժ�Ҫ�ر���
	connection c = connect(&d);
	//shared_ptr<T> p(q, d) p�ӹ�������ָ��q��ָ��Ķ��������Ȩ��p��ʹ�ÿɵ��ö���d������delete
	
	shared_ptr<connection> p(&c, end_connection);
	//shared_ptr<connection> p(&c, [](connection *a) {return disconnect(*a); });
	cout << "connecting now...(" << p.use_count() << ")" << endl;
	//ʹ������
	//�˳�ǰ���ǵ���disconnect�����޷��ر�c��
}

//12.1.4 ����ָ����쳣
void Fun_Smart_Pointers_and_Exceptions()
{
	//ʹ������ָ�룬��������������߷����쳣���º����˳����ֲ����󶼻ᱻ���٣��ڴ�ᱻ�ͷ�
	//ʹ������ָ������ڴ棬��new֮���Ӧ��delete֮ǰ�����쳣���ڴ治�ᱻ�ͷ�

	//����ָ������ࣨû�ж�������������
	//ʹ�������Լ����ͷŲ���
	//��һ��share_ptr������ʱ����Ĭ�ϵض��������ָ�����delete������
	//���Ƕ���һ������������delete �����ɾ�������������ܹ���ɶ�shared_ptr�б����ָ������ͷŵĲ���


	//����ָ�����壺ʹ������ָ���ֵĻ����淶
	//��ʹ����ͬ������ָ��ֵ��ʼ������reset���������ָ��
	//��delete get()���ص�ָ��
	//��ʹ��get()��ʼ����reset��һ������ָ��
	//���ʹ��get()���ص�ָ�룬�����һ����Ӧ������ָ�����ٺ�ָ�����Ч��
	//���ʹ������ָ��������Դ����new������ڴ棬��ס���ݸ���һ��ɾ����

	//ex12.14
	
	//ex12.15
	//destination dest("202.118.176.67", 3316);
	//f(dest);
}

void f_uniqptr(destination &d)
{
	connection c = connect(&d);
	unique_ptr<connection, decltype(end_connection)*> uni_p(&c, end_connection);
	//ʹ������
	//��f_uniqptr�˳�ʱ����ʹ�������쳣�˳���connection�ᱻ��ȷ�ر�
}

//12.1.5 unique_ptr
void Fun_unique_ptr()
{
	//ĳ��ʱ��ֻ����һ��unique_ptrָ��һ����������
	//����unique_ptrʱ����Ҫ����󶨵�һ��new���ص�ָ���ϣ���ʼ���������ֱ�ӳ�ʼ��
	//unique_ptr��֧����ͨ�Ŀ�����ֵ����
	//unique_ptr<string> p1(new string("hello"));
	//cout << *p1 << endl;						//
	//unique_ptr<string> p2(p1.release());		//p1������ָ��Ŀ���Ȩ������ָ�룬�ڴ�����Ȩת��p2������p1��Ϊ��
	//cout << *p2 << endl;
	//unique_ptr<string> p3(new string("Trex"));
	//p2.reset(p3.release());						//reset�ͷ���p2ԭ��ָ����ڴ棬����Trex���ڴ�����Ȩ��p3ת����p2
	//cout << *p2 << endl;
	////p3 = nullptr;		//�ͷ�p3��ָ��Ķ��󣬽�p3��Ϊ��
	////release���ص�ָ��ͨ��������ʼ����һ������ָ������һ������ָ�븳ֵ
	////p2.release();		//p2�����ͷ��ڴ棬�������Ƕ�ʧ��ָ��
	//auto p = p2.release();	//һ����ָͨ�뱣��release���ص�ָ�룬����Ҫ������Դ���ͷ�
	//delete p;

	//����unique_ptr�����ͷ���unique_ptr
	//���ǿ��Կ�����ֵһ����Ҫ�����ٵ�unique_ptr

	//��unique_ptr����ɾ����
	//���Ǳ����ڼ�������unique_ptrָ�������֮���ṩɾ��������
	//�ڴ�����resetһ������unique_ptr���͵Ķ���ʱ�������ṩһ��ָ�����͵Ŀɵ��ö���ɾ������

	//ex12.16
	//unique_ptr<int> p1(new int(5));
	//unique_ptr<int> p2;
	////p2 = p1;
	////p2.reset(p1.release());
	//cout << *p2 << endl;
	
	//ex12.17
	//int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	//typedef unique_ptr<int> IntP;
	//IntP p0(ix);  //������int���ͳ�ʼ��unique_ptr<int>
	//IntP p1(pi);	//����ͨ�����룬���ǳ���p1���÷�Χ��p1�����٣�������delete�ͷŸö��󣬵���1024�����Ƕ�̬�ڴ棬�ᱨ��
	//IntP p2(pi2);	//���Ա��룬���ǻᵼ�¿���ָ�루pi2��
	//IntP p3(&ix);	//���ǳ���p3���÷�Χ,�����delete����һ�����Ƕ�̬�ڴ�Ķ���
	//IntP P4(new int(2048));  //��ȷ
	//IntP p5(p2.get());		//�����˫���ͷ�

	//ex12.18
	//��Ϊunique_ptr��ӵ�С�����ָ��Ķ���shared_ptr��������������ָ�빲����󣬲���Ҫ�ͷ�

}

int main()
{
	//12.1.1 shared_ptr��
	//Fun_The_shared_ptr_Class();
	//12.1.2 ֱ�ӹ����ڴ�
	//Fun_Managing_Memory_Directly();
	//12.1.3 shared_ptr��new���ʹ��
	//Fun_Using_shared_ptrs_with_new();
	//12.1.4 ����ָ����쳣
	//Fun_Smart_Pointers_and_Exceptions();
	//12.1.5 unique_ptr
	Fun_unique_ptr();

	return 0;
}
