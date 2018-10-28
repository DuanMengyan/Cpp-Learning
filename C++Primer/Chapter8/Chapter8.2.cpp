#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter8.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018��10��27�� ������
> Last edited time: 2018��10��27�� ������
> Topic:C++Primer Chapter8.2 �ļ��������
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;


//8.2 �ļ��������
//8.2 File Input and Output

//8.2.1 ʹ���ļ�������
void Fun_Using_File_Stream_Objects()
{
	//string ifile = "input_file.txt";
	//string ofile = "output_file.txt";
	//ifstream input(ifile);			//�����ۼ�¼�ļ�
	//ofstream output(ofile);			//������ļ�
	//Sales_data total;				//���������ܶ�ı���
	//if (read(input, total))			//��ȡ��һ�����ۼ�¼
	//{								
	//	Sales_data trans;			//������һ�����ۼ�¼�ı���
	//	while (read(input, trans))						//
	//	{												//
	//		if (total.isbn() == trans.isbn())
	//			total.combine(trans);
	//		else
	//		{
	//			print(output, total);
	//			total = trans;
	//		}
	//	}
	//	print(output, total);
	//}
	//else
	//{
	//	cerr << "No data?!" << endl;
	//}

	//��Ա����open��close
	//string ifile = "text";
	//ifstream in(ifile + ".txt");
	//ofstream out;
	//out.open(ifile + ".txt");
	//out.close();
	//out.open(ifile + "_copy.txt");
	//if (out)
	//{
	//	out << "open!" << endl;
	//}
	//else
	//{
	//	cerr << "error!" << endl;
	//}


	//�Զ�����ͽ���
	//vector<string> vec_file{"text.txt","test.txt","text_copy.txt"};
	//string tempstring;
	//for (string filename : vec_file)
	//{
	//	ifstream input(filename);			//input�Ǿֲ�������ÿ��ѭ����Ҫ����������һ��
	//										//fstream�����뿪�������ǣ���֮�������ļ��Զ��ر�
	//	if (input)
	//	{
	//		getline(input,tempstring);
	//		cout << tempstring + " " + filename << endl;
	//	}
	//	else
	//	{
	//		cerr << "couldn't open: " + filename;
	//	}
	//}

	//ex8.4-ex8.5
	//vector<string> vec_string;
	//ifstream input("text.txt");
	//if (input)
	//{
	//	string temp;
	//	//while (getline(input, temp))
	//	while (input>>temp)
	//	{
	//		vec_string.push_back(temp);
	//	}
	//}
	//for (string str : vec_string)
	//	cout << str << endl;
	
	//ex8.6
	

}

//8.2.2 �ļ�ģʽ
void Fun_File_Modes()
{
	//��outģʽ����д�ķ�ʽ�򿪣����ļ��ᶪ����������
	//app��ÿ��д����ǰ����λ���ļ�ĩβ
	//ate�����ļ���������λ���ļ�ĩβ
	
	//file1���ضϣ�ԭ������ʧ
	//ofstream out1("file1.txt");
	//ofstream out2("file1.txt", ofstream::out);
	//ofstream out3("file1.txt", ofstream::out|ofstream::trunc);

	//Ϊ����file2ԭ���ݣ�������ʾָ��appģʽ
	//ofstream out1("file2.txt");
	//ofstream out2("file2.txt", ofstream::app);
	//ofstream out3("file2.txt", ofstream::out | ofstream::trunc);

	//ÿ�ε���openʱ����ȷ���ļ�ģʽ
	//ofstream out;								//δָ���ļ���ģʽ
	//out.open("file_mode.txt");					//Ĭ��Ϊ����ͽض�
	//out << "filemode:reunc" << endl;			//�ļ�ԭ��������ʧ��
	//out.close();								//�ر�out�����������ļ�
	//out.open("file_mode2.txt", ofstream::app);	//ģʽΪ�����׷��
	//out << "filemode:app" << endl;				//�ļ�ԭ���ݱ���
	//out.close();
	
	//ex8.7

	//ex8.8
}


int main(int argc, char **argv)
{
	//ex8.7-ex8.8
	//ifstream input(argv[1]);			//�����ۼ�¼�ļ�
	//ofstream output(argv[2],ofstream::app);			//������ļ�
	//Sales_data total;				//���������ܶ�ı���
	//if (read(input, total))			//��ȡ��һ�����ۼ�¼
	//{								
	//	Sales_data trans;			//������һ�����ۼ�¼�ı���
	//	while (read(input, trans))						//
	//	{												//
	//		if (total.isbn() == trans.isbn())
	//			total.combine(trans);
	//		else
	//		{
	//			print(output, total);
	//			total = trans;
	//		}
	//	}
	//	print(output, total);
	//}
	//else
	//{
	//	cerr << "No data?!" << endl;
	//}
	//8.2.1 ʹ���ļ�������
	//Fun_Using_File_Stream_Objects();
	//8.2.2 �ļ�ģʽ
	//Fun_File_Modes();
	return 0;
}