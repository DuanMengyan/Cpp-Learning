#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter8.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月26日 星期五
> Last edited time: 2018年10月27日 星期六
> Topic:C++Primer Chapter8.1 IO类
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

//8.1 IO类
void Fun_The_IO_Classes()
{
	//8.1.1 IO对象无拷贝或赋值
	//8.1.2 条件状态
	//代码通常应该在使用一个流之前检查他是否处于良好状态
	//while (cin>>word)  //循环检查表达式返回的留的状态

	//管理条件状态

	//流对象的rdstate成员返回一个iostate值，对应流的当前状态
	//auto old_state = cin.rdstate();
	//cin.clear();
	//process_input(cin);
	//cin.setstate(old_state);

	//ex8.1-ex8.2
	//auto old_state = cin.rdstate();
	//cout << cin.rdstate() << endl;
	//istream &is = func(cin);
	//cout << is.rdstate() << endl;
	//cout << func(cin).rdstate() << endl;  //func会再次执行
	//cout << is.rdstate() << endl;

	//ex8.3
	//将cin置于错误状态，while循环终止，badbit、failbit、eofbit
	
	

	//8.1.3管理输出缓冲
	
	//缓冲区的刷新,即数据真正写到输出设备或文件：
	//下列情况会引发缓冲区的刷新 :
	//  1、缓冲区满时，刷新缓冲，而后新的数据才能继续写入缓冲区；
	//	2、执行flush语句，但不输出任何额外的字符；ends操纵符向缓冲区插入一个空字符，然后刷新
	//	3、执行endl语句，显示刷新缓冲区；
	//	4、关闭文件。
	//	5. 一个输出流可能被关联到另一个流。读写被关联的流时，关联到的流的缓冲区会被刷新
	//	6. 输出操作后，用操纵符unitbuf设置流的内部状态，来清空缓冲区

	//刷新缓冲区
	//cout << "hi!" << endl;		//换行，刷新缓冲区
	//cout << "hi!" << flush;		//刷新缓冲区，不加额外字符；
	//cout << "hi!" << ends;		//输出一个空字符，然后刷新缓冲区

	//unitbuf操纵符
	//告诉流在接下来每次操作之后都进行一次flush操作。
	//nounitbuf重置流，使其恢复正常的缓冲区刷新机制


	//关联输入和输出流
	//当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流
	//标准库将cout和cin关联在一起
	//交互式系统应该关联输入流和输出流
	//x.tie(&o)将流x关联到输出流o


	//创建文件test.txt并打开
	ofstream outfile("test.txt");
	
	//向test.txt文件中写入4096个字符’a’
	//全缓冲大小是4096个字节
	for (int n = 0; n < 4096; ++n)
	{
		outfile << 'a';
	}

	//此时打开test.txt文件，文件为空，4096个a还在缓冲区，并没有执行真正的I/O操作
	//暂停，按任意键继续
	system("PAUSE");

	//此时再打开test.txt文件，文件中已经有了4096个字符“a”。
	//这说明全缓冲区的大小是4K（4096），缓冲区满后执行了I/O操作，而字符“b”还在缓冲区。
	//继续向test.txt文件中写入字符’b’，也就是说，第4097个字符是’b’
	outfile <<'b';

	//暂停，按任意键继续
	system("PAUSE");
	//程序结束，文件关闭，刷新缓冲区，字符b也出现在文件中
}







//int main()
//{
//	//8.1 IO类
//	Fun_The_IO_Classes();
//	return 0;
//}