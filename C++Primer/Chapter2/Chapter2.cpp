#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年07月28日 星期六
> Last edited time: 2018年07月28日 星期六
> Topic:C++Primer Chapter2
************************************************************************/



#include <iostream>//系统头文件的文件名要放在尖括号里给出，这是告诉编译器：应该到“标准的”地点寻找这个文件：#include <stdio.h>
#include "temp.h"//自定义头文件的文件名要放在双引号里给出

using namespace std;

//2.3算数类型转换
void DataType() 
{ 		
	//unsigned int u = 10;		
	//int i = -42;	
	//std::cout << i + i << std::endl;	
	//std::cout << u + i << std::endl;	
	//unsigned u1 = 42, u2 = 10;	
	//std::cout << u1 - u2 << std::endl;
	//std::cout << u2 - u1 << std::endl;
	 
	
	//for (unsigned i = 10; i >= 0; --i)  //无符号的i永远也不会小于0，这种写法错误
	//	std::cout << i << std::endl;	
	
	
	
	/*表达式中既有带符号类型又有无符号类型；	
	当符号类型取值为负时，出现异常结果；
	因为带符号类型数会自动转换为无符号数。	*/
	
	int a = -1;	unsigned b = 1;	
	std::cout << a * b << std::endl;		//a转换为取模无符号数4294967295，结果为：4294967295
	unsigned u = 10, u2 = 42;	
	std::cout << u2 - u << std::endl;		//32	
	std::cout << u - u2 << std::endl;		//结果-32超出无符号类型范围，出现异常
	int i = 10, i2 = 42;	
	std::cout << i2 - i<< std::endl;		//32	
	std::cout << i - i2 << std::endl;		//-32	
	std::cout << i- u << std::endl;			//0	
	std::cout << u - i << std::endl;		//0


}

//2.8字面值常量
void LiteralConstant()  
{
	std::cout << "Hi \x4dO\115!\n";
	std::cout << '\115' << '\n';

	std::cout << "2\115" << std::endl;
	std::cout << '2' << '\t' << '\x4d' << std::endl;
}


std::string global_str; //定义在
int global_int;
//2.10变量初始值
/*
/如果在定义变量时没有指定初值，那么变量会被默认初始化。
/三条性质：
/1、定义在任何函数体外的变量会被初始化为0。   
/2、定义在函数体内部的变量不会被初始化。 
/3、类的对象未被初始化，则初值由类决定。
*/
void VariableInitialValue()
{
	int local_int = 1;
	std::string local_str;
	std::cout << &global_str << std::endl;
	std::cout << global_int << std::endl;
	std::cout << &local_str << std::endl;
	std::cout << local_int << std::endl;
}


//2.11变量声明与定义
/*
声明：使得名字为程序所知，如果想使用该变量，则必须实现包含其声明。声明会确定变量的名字和类型。

定义：创建与名字关联的实体。定义会申请存储空间，可能会赋予初始值。

如果想声明一个变量而不想定义它，那么可以在变量名前加extern关键字。
*/
void VariableDefinitionAndDeclaration()
{
	int variable = 10; //定义变量variable
	std::cout << variable << std::endl;
}

//2.15引用
void Reference()
{	
	//int ival = 1.01;   //不合法的定义
	//int &rval1 = 1.01;


}
int i = 42;

int main()
{

	//DataType();
	//LiteralConstant();
	//VariableInitialValue();
	//VariableDefinitionAndDeclaration();

	//Reference();


	int i = 100;
	int j = i;
	std::cout << j << std::endl;


	return 0;
}



