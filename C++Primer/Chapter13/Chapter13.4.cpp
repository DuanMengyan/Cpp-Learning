#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.4.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��3��1�� ������
> Last edited time: 2019��3��2�� ������
> Topic:C++Primer Chapter13.4 ��������ʵ��
************************************************************************/

#include "header_include.h"
//#include "Sales_data.h"
//#include "StrBlob.h"
//#include "StrBlobPtr.h"
//#include "HasPtr.h"
//#include "HasPtr2.h"
#include "Folder.h"
#include "Message.h"


using namespace std;

//Chapter13.4 ��������ʵ��
void Fun_A_Copy_Control_Example()
{
	//������ֵ�����ͨ��ִ�п������캯��������������ҲҪ���еĹ���
	//�������ֿ�����private���ߺ��������

	//ex13.33
	//��Ϊ�ں�����Ҫ��Folder��Ա�����޸ģ����Զ���Ϊ��const�������ͣ�
	//�����Folder����Ŀ�����Ҳ��֤�޸ĳɹ�

	//ex13.34
	
	//ex13.35
	//�ϳɵĿ������Ƴ�Ա���ܸ���folders��������Ϣ�����

	//ex13.36

	//�ڶ����Folder��Message��֮��һֱ�б���
	//����һ��debug֮�󣬷�����Folder����������ִ�д���
	//�ٺ���������Folder����ʱ��һ����Χѭ�����ִ�д���
	//��ѭ����ɾ����set_m�е�Ԫ�أ������˵�����ʧЧ��ѭ������
	//C++Primer 5th��315ҳ��9.3.6�� �������������ǵ���������ʧЧ
	//�����������Ԫ�ػ���������ɾ��Ԫ�صĲ������ܻ�ʹָ������Ԫ�ص�ָ�롢���û������ʧЧ�����������صĴ���
	//��˶�����������ɾ������Ҫע�����¶�λָ�롢���û��������ѭ����������Ҫ
	
		
	Folder work("work"), study("study");
	
	
	Message m1("m1"), m2("m2"), m3("m3"), m4("m4");

	m1.save_to_Folder(work); m1.save_to_Folder(study);
	m2.save_to_Folder(work);
	m3.save_to_Folder(work); m3.save_to_Folder(study);
	m4.save_to_Folder(work);
	m1.print_folders();
	m2.print_folders();
	m3.print_folders();
	m4.print_folders();

	//��ӡFolder�е�Message
	cout << "***** work *****" << endl;
	work.print_messages();
	cout << "***** study *****" << endl;
	study.print_messages();

	cout << endl << "=======================" << endl;

	//�������캯��
	Folder work2(work);

	cout << endl << "=======================" << endl;
	
	//������ֵ�����
	study = work;
	study.print_messages();

	cout << endl << "=======================" << endl;
	work2.print_messages();

	//ex13.37
	//�����ļ�

	//ex13.38
	//ʹ�ö�̬������ڴ�ʱ�����ƺͽ�����һ�����ŵķ�ʽ�� 
	//��Message���У���û���漰����̬�ڴ���䡣 
	//��ˣ�ʹ�����ֹ����﷨��û������ģ���������ָ����ߵ�ָ�뽫ʹ������ӡ�

	//����������£���������������ġ� 
	//�����������Message���ļ��У�Ȼ�󽻻���Ա�������Լ���ӵ�ÿ���ļ��С� 
	//���ǣ�Message�Ŀ�����ֵ�����ֻ������Լ��������Ƴ�Ա�������Լ���ӵ�ÿ���ļ��С� 
	//rhs����Ҫ�������ӵ��ļ��С� 
	//��ˣ����ʹ��copy��swap�����壬�ǽ��Ƿǳ���Ч�ġ�



}


int main()
{
	//Chapter13.4 ��������ʵ��
	Fun_A_Copy_Control_Example();
	return 0;
}
