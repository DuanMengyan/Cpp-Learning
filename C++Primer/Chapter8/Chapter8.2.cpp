#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter8.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月27日 星期六
> Last edited time: 2018年10月27日 星期六
> Topic:C++Primer Chapter8.2 文件输入输出
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"

using namespace std;


//8.2 文件输入输出
//8.2 File Input and Output

//8.2.1 使用文件流对象
void Fun_Using_File_Stream_Objects()
{
	//string ifile = "input_file.txt";
	//string ofile = "output_file.txt";
	//ifstream input(ifile);			//打开销售记录文件
	//ofstream output(ofile);			//打开输出文件
	//Sales_data total;				//保存销售总额的变量
	//if (read(input, total))			//读取第一条销售记录
	//{								
	//	Sales_data trans;			//保存下一条销售记录的变量
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

	//成员函数open和close
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


	//自动构造和解析
	//vector<string> vec_file{"text.txt","test.txt","text_copy.txt"};
	//string tempstring;
	//for (string filename : vec_file)
	//{
	//	ifstream input(filename);			//input是局部变量，每次循环都要创建和销毁一次
	//										//fstream对象离开作用于是，与之关联的文件自动关闭
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

//8.2.2 文件模式
void Fun_File_Modes()
{
	//以out模式（以写的方式打开）打开文件会丢弃已有数据
	//app，每次写操作前均定位到文件末尾
	//ate，打开文件后立即定位到文件末尾
	
	//file1被截断，原内容消失
	//ofstream out1("file1.txt");
	//ofstream out2("file1.txt", ofstream::out);
	//ofstream out3("file1.txt", ofstream::out|ofstream::trunc);

	//为保留file2原内容，必须显示指定app模式
	//ofstream out1("file2.txt");
	//ofstream out2("file2.txt", ofstream::app);
	//ofstream out3("file2.txt", ofstream::out | ofstream::trunc);

	//每次调用open时都会确定文件模式
	//ofstream out;								//未指定文件打开模式
	//out.open("file_mode.txt");					//默认为输出和截断
	//out << "filemode:reunc" << endl;			//文件原来内容消失，
	//out.close();								//关闭out，用于其他文件
	//out.open("file_mode2.txt", ofstream::app);	//模式为输出和追加
	//out << "filemode:app" << endl;				//文件原内容保留
	//out.close();
	
	//ex8.7

	//ex8.8
}


int main(int argc, char **argv)
{
	//ex8.7-ex8.8
	//ifstream input(argv[1]);			//打开销售记录文件
	//ofstream output(argv[2],ofstream::app);			//打开输出文件
	//Sales_data total;				//保存销售总额的变量
	//if (read(input, total))			//读取第一条销售记录
	//{								
	//	Sales_data trans;			//保存下一条销售记录的变量
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
	//8.2.1 使用文件流对象
	//Fun_Using_File_Stream_Objects();
	//8.2.2 文件模式
	//Fun_File_Modes();
	return 0;
}