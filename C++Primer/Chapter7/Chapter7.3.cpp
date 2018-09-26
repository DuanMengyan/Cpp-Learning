#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月26日 星期三
> Last edited time: 2018年9月24日 星期三
> Topic:C++Primer Chapter7.3 类的其他特性
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

class Screen
{
public:
	void some_menber() const;
	typedef string::size_type pos;   //用来定义类型的成员必须先定义后使用
	//using pos = string::size_type;
	Screen() = default;						//告诉编译器合成默认的构造函数
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}   //默认inline
	char get() const						//读取光标处的字符
	{
		return contents[cursor];			//隐式内联，默认inline
	}
	inline char get(pos ht, pos wd) const;	//显式内联
	Screen &move(pos r, pos c);				//能在之后被设为内联
	void get_string()
	{
		//按照行列打印字符串内容
		for (decltype(height) i = 0; i != height; ++i)
		{
			for (decltype(width) j = 0; j != width; ++j)
			{
				cout << contents[i*width+j] <<" ";
			}
			cout << endl;
		}	
	}
private:
	mutable size_t access_ctr;		//即使在一个const对象内也能被修改+

	pos cursor = 0;		//光标
	pos height = 2, width = 7;
	string contents = "ABCDEFGHIJKLMN";
};

void Screen::some_menber() const
{
	++access_ctr;		//保存一个计数值，用于记录成员函数被调用的次数
}

inline 
Screen &Screen::move(pos r,pos c)
{
	pos row = (r-1)*width;			//计算行的位置
	cursor = row + (c-1);			//在行内将光标移动到指定的列
	return *this;				//以左值的形式返回对象
}

char Screen::get(pos r,pos c) const
{
	//r行c列上的字符
	pos row = (r-1)*width;
	return contents[row+(c-1)];
}

class Window_mgr
{
private:
	//这个window_mgr追踪的Screen
	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	vector<Screen> screens{ Screen(24, 80, '  ') };  //列表初始化
};
//7.3.1 类成员再探
void Fun_Class_Members_Revisited()
{
	//定义一个类型成员
	
	//令成员作为内联函数
	//定义于类内部的成员函数是自动inline的
	//也可以在类的外部用inline关键字修饰函数的定义
	Screen myscreen;  //5行2列全是字符D
	myscreen.get_string();
	char ch = myscreen.get();	 //光标当前位置的字符(第1行第1列)
	cout << ch << endl;
	ch = myscreen.get(1, 2);	 //第1行第2列的字符
	cout << ch << endl;
	

	//可变数据成员（mutable data menber）
	//一个可变数据成员永远不会是const，即使它是const对象的成员

	//类数据成员的初始值
	//当我们提供一个类内初始值是，必须以符号=或者花括号表示


}


int main()
{
	//7.3.1 类成员再探
	Fun_Class_Members_Revisited();
	return 0;
}
