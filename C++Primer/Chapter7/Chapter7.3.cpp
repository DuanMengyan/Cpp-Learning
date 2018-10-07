#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter7.3.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年9月26日 星期三
> Last edited time: 2018年10月7日 星期日
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

class Screen;

class Window_mgr
{
public:
	//窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type;
	//按照编号将指定的Screen重置为空白
	void clear(ScreenIndex);
private:
	//std::vector<Screen> screens{ Screen(24, 80, ' ') };
	std::vector<Screen> screens;
};


class Screen
{	

public:
	//Window_mgr的成员可以访问Screen类的私有部分
	//friend class Window_mgr;
	//令成员函数作为友元
	friend void Window_mgr::clear(ScreenIndex);
	
	void some_menber() const;
	typedef string::size_type pos;   //用来定义类型的成员必须先定义后使用
	//using pos = string::size_type;
	
	Screen &set(char);					//设置当前光标处所在位置字符	
	Screen &set(pos, pos, char);		//设置指定位置字符

	//构造函数
	Screen() = default;						//告诉编译器合成默认的构造函数
	Screen(pos ht, pos wd) :height(ht), width(wd),contents(ht*wd,'*') { };
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){ }   //默认inline
	
	char get() const						//读取光标处的字符
	{
		return contents[cursor];			//隐式内联，默认inline
	}
	inline char get(pos ht, pos wd) const;	//显式内联
	
	Screen &move(pos r, pos c);				//能在之后被设为内联
	
	const Screen &display(ostream &os) const
	{
		cout << "Const:" << endl;
		do_display(os);
		return *this;
	}

	Screen &dispaly(ostream &os) 
	{
		cout << "No const:" << endl;
		do_display(os);
		return *this;
	}

private:
	mutable size_t access_ctr;		//即使在一个const对象内也能被修改+

	pos cursor = 0;		//光标
	pos height = 2, width = 7;
	string contents = "ABCDEFGHIJKLMN";

	void do_display(ostream &os) const
	{
		//按照行列打印字符串内容
		for (decltype(height) i = 0; i != height; ++i)
		{
			for (decltype(width) j = 0; j != width; ++j)
			{
				os << contents[i*width + j] << " ";
			}
			os << endl;
		}
		//os << contents << endl;
	}
};


void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height*s.width, ' ');
}


inline 
Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline
Screen &Screen::set(pos row,pos col,char ch)
{
	if (row > 0 && col > 0)
	{
		contents[(row - 1)*width + (col - 1)] = ch;
		return *this;
	}
	else
	{
		cout << "Set error!" << endl;
		return *this;
	}

}

void Screen::some_menber() const
{
	++access_ctr;		//保存一个计数值，用于记录成员函数被调用的次数
}

inline 
Screen &Screen::move(pos r,pos c)
{
	if (r > 0 && c > 0)
	{
		pos row = (r - 1)*width;			//计算行的位置
		cursor = row + (c - 1);			//在行内将光标移动到指定的列
		return *this;				//以左值的形式返回对象
	}
	else
	{
		cout << "Move error!" << endl;
		return *this;
	}
}

char Screen::get(pos r,pos c) const
{
	//r行c列上的字符
	if (r > 0 && c > 0)
	{
		pos row = (r - 1)*width;
		return contents[row + (c - 1)];
	}
	else
	{
		cout << "Get error!" << endl;		
	}
}


//class Window_mgr
//{
//private:
//	//这个window_mgr追踪的Screen
//	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
//	//vector<Screen> screens{ Screen(24, 80, ' ') };  //列表初始化
//};

//7.3.1 类成员再探
void Fun_Class_Members_Revisited()
{
	//定义一个类型成员
	
	//令成员作为内联函数
	//定义于类内部的成员函数是自动inline的
	//也可以在类的外部用inline关键字修饰函数的定义
	//Screen myscreen;  //5行2列全是字符D
	//myscreen.dispaly(cout);
	//char ch = myscreen.get();	 //光标当前位置的字符(第1行第1列)
	//cout << ch << endl;
	//ch = myscreen.get(1, 2);	 //第1行第2列的字符
	//cout << ch << endl;
	
	//可变数据成员（mutable data menber）
	//一个可变数据成员永远不会是const，即使它是const对象的成员

	//类数据成员的初始值
	//当我们提供一个类内初始值是，必须以符号=或者花括号表示

	//ex7.25
	//不能，因为只有内置类型和string可以依赖于拷贝和赋值操作的默认版本

	//ex7.26
	//在类体外定义直接加inline即可，体内声明为inline也可，但要保持一致。

}

//7.3.2 返回*this的成员函数
void Fun_Functions_That_Return_this()
{
	//Screen myscreen1(5,5);
	//const Screen myscreen2(5,5,'&');
	////如果报错：对象包含与成员函数不兼容的限定符，把下面一句重新打一遍，调用兼容的重载函数
	//myscreen2.display(cout);
	//cout << endl;
	//myscreen1.move(2,2).set('@');
	//myscreen1.dispaly(cout).set('$');
	//cout << endl;
	//myscreen1.set(1, 2, '#');
	//myscreen1.dispaly(cout);
	//cout << endl;

	//从const成员函数返回*this
	//基于const的重载

	//ex7.27
	Screen myScreen(5, 5, 'X');
	//把光标移动到第4行第1列，将(4,2)位置字符改为#，然后输出
	myScreen.move(4, 1).set('#').dispaly(cout); 
	cout << endl;
	myScreen.dispaly(cout);
	cout << endl;

	//ex7.28
	//若函数返回类型变为Screen，则返回的是对象的副本，
	//函数的操作只能作用于对象的副本上，对象的本身并不会发生改变

	//ex7.30
	//优点：
	//1.当需要一个对象作为整体引用而不是引用对象的一个成员时，使用this，
	//则该函数返回对调用该函数的对象的引用。
	//2.可以非常明确地指出访问的是调用该函数的对象的成员，
	//且可以在成员函数中使用与数据成员同名的形参。
	//
}

//7.3.3 类类型
void Fun_Class_Types()
{
	//类的声明
	//class Screen;   //类Screen的声明，仅声明而不定义

	//不完全类型使用场景：
	//定义指向这种类型的指针或引用；
	//声明（但是不能定义）以不完全类型作为参数或者返回类型的函数

	//在创建一个类的对象之前，该类必须被定义过，而不能仅仅被声明。

	//ex7.31
	//class Y;

	//class X
	//{
	//	Y *ptr_Y = nullptr;
	//};

	//class Y
	//{
	//	X x1;
	//};
}



struct X
{
	friend void f(){/*友元函数可以定义在类的内部*/}
	//X(){ f(); }				//错误，f还未被声明
	void g();
	void h();
};

//void X::g(){ return f(); }		//错误，f还未被声明
void f();						//声明定义在X中的友元函数f
void X::h(){ return f(); }

//7.3.4 友元再探
void Fun_Friendship_Revisited()
{
	//友元函数能定义在类的内部，这样的函数是隐式内联的

	//类之间的友元关系
	//Window_mgr是Screen的友元类，友元类的成员函数可以访问此类包括非公有成员在内的所有成员
	//友元关系不存在传递性，Window_mgr的友元不具有访问Screen的特权
	//每个类负责控制自己的友元类或友元函数

	//令成员函数作为友元
	//1.首先定义Window_mgr类，其中声明clear函数，但是不定义它。
	//	在clear使用Screen的成员函数之前必须先声明Screen。
	//2.接下来定义Screen，包括对于clear的友元声明
	//3.最后定义clear，此时它才可以使用Screen的成员。

	//函数重载和友元
	//如果想把一组重载函数声明成它的友元，需要对这组函数中的每一个分别声明

	//友元声明和作用域




}



int main()
{
	//7.3.1 类成员再探
	//Fun_Class_Members_Revisited();
	//7.3.2 返回*this的成员函数
	//Fun_Functions_That_Return_this();
	//7.3.3 类类型
	//Fun_Class_Types();
	//7.3.4 友元再探
	Fun_Friendship_Revisited();
	return 0;
}
