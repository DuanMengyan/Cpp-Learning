#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter8.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��26�� ������
> Last edited time: 2018��10��27�� ������
> Topic:C++Primer Chapter8.1 IO��
************************************************************************/

#include "header_include.h"

using namespace std;

//ex8.1-ex8.2
istream &func(istream &is)
{
	string buf;
	while (is>>buf)
	{
		cout << buf << endl;
	}
	is.clear();
	return is;
}

//8.1 IO��
void Fun_The_IO_Classes()
{
	//8.1.1 IO�����޿�����ֵ
	//8.1.2 ����״̬
	//����ͨ��Ӧ����ʹ��һ����֮ǰ������Ƿ�������״̬
	//while (cin>>word)  //ѭ�������ʽ���ص�����״̬

	//��������״̬

	//�������rdstate��Ա����һ��iostateֵ����Ӧ���ĵ�ǰ״̬
	//auto old_state = cin.rdstate();
	//cin.clear();
	//process_input(cin);
	//cin.setstate(old_state);

	//ex8.1-ex8.2
	//auto old_state = cin.rdstate();
	//cout << cin.rdstate() << endl;
	//istream &is = func(cin);
	//cout << is.rdstate() << endl;
	//cout << func(cin).rdstate() << endl;  //func���ٴ�ִ��
	//cout << is.rdstate() << endl;

	//ex8.3
	//��cin���ڴ���״̬��whileѭ����ֹ��badbit��failbit��eofbit
	
	

	//8.1.3�����������
	
	//��������ˢ��,����������д������豸���ļ���
	//���������������������ˢ�� :
	//  1����������ʱ��ˢ�»��壬�����µ����ݲ��ܼ���д�뻺������
	//	2��ִ��flush��䣬��������κζ�����ַ���ends���ݷ��򻺳�������һ�����ַ���Ȼ��ˢ��
	//	3��ִ��endl��䣬��ʾˢ�»�������
	//	4���ر��ļ���
	//	5. һ����������ܱ���������һ��������д����������ʱ�������������Ļ������ᱻˢ��
	//	6. ����������ò��ݷ�unitbuf���������ڲ�״̬������ջ�����

	//ˢ�»�����
	//cout << "hi!" << endl;		//���У�ˢ�»�����
	//cout << "hi!" << flush;		//ˢ�»����������Ӷ����ַ���
	//cout << "hi!" << ends;		//���һ�����ַ���Ȼ��ˢ�»�����

	//unitbuf���ݷ�
	//�������ڽ�����ÿ�β���֮�󶼽���һ��flush������
	//nounitbuf��������ʹ��ָ������Ļ�����ˢ�»���


	//��������������
	//��һ����������������һ�������ʱ���κ���ͼ����������ȡ���ݵĲ���������ˢ�¹����������
	//��׼�⽫cout��cin������һ��
	//����ʽϵͳӦ�ù����������������
	//x.tie(&o)����x�����������o


	//�����ļ�test.txt����
	ofstream outfile("test.txt");
	
	//��test.txt�ļ���д��4096���ַ���a��
	//ȫ�����С��4096���ֽ�
	for (int n = 0; n < 4096; ++n)
	{
		outfile << 'a';
	}

	//��ʱ��test.txt�ļ����ļ�Ϊ�գ�4096��a���ڻ���������û��ִ��������I/O����
	//��ͣ�������������
	system("PAUSE");

	//��ʱ�ٴ�test.txt�ļ����ļ����Ѿ�����4096���ַ���a����
	//��˵��ȫ�������Ĵ�С��4K��4096��������������ִ����I/O���������ַ���b�����ڻ�������
	//������test.txt�ļ���д���ַ���b����Ҳ����˵����4097���ַ��ǡ�b��
	outfile <<'b';

	//��ͣ�������������
	system("PAUSE");
	//����������ļ��رգ�ˢ�»��������ַ�bҲ�������ļ���
}







//int main()
//{
//	//8.1 IO��
//	Fun_The_IO_Classes();
//	return 0;
//}