#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.5.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月1日 星期二
> Last edited time: 2019年1月1日 星期二
> Topic:C++Primer Chapter10.5 泛型算法结构
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "Sales_item.h"


using namespace std;

//Chapter10.5 泛型算法结构
//


//10.5.1 5类迭代器
void Fun_The_Five_Iterator_Categories()
{
	//ex10.38
	//(1)输入迭代器(==,!=,++,*,->)
	//进行比较的相等和不等运算符（==,!=）
	//支持前置和后置的递增运算符（++）
	//支持读取元素的解引用运算符（*）；出现在赋值运算符的右侧
	//箭头运算符（->）,解引用迭代器，获取对象的成员
	//(2)输出迭代器(++,*)
	//用于推进迭代器的前值和后置递增运算符（++）
	//解引用运算符，只出现在赋值运算符的左侧
	//(3)前向迭代器(++,==,!=,*,->)
	//可以读写元素，只能沿一个方向移动
	//支持输入和输出迭代器的所有操作
	//使用前向迭代器可以对序列进行多遍扫描
	//(4)双向迭代器(++,--,==,!=,*,->)
	//正向/反向读取序列中的元素
	//支持前置和后置递减运算符（--）
	//(5)随机访问迭代器(++,--,==,!=,*,->,>,<,>=,<=,+,-,+=,-=，-(two iterators),iter[n]==*(iter+n))
	//提供在序列中访问任意元素的能力
	//支持迭代器相减，比较大小（前后）

	//ex10.39
	//list上的迭代器属于双向迭代器
	//vector上的迭代器属于随机访问迭代器

	//ex10.40
	//copy要求前两个迭代器参数要求输入迭代器，最后一个要求输出迭代器
	//reverse双向迭代器
	//unique要求前向迭代器
}



//10.5.2 算法形参模式
void Fun_Algorithm_Parameter_Patterns()
{
	//接收单个目标迭代器的算法
	//假定目标空间足够容纳写入的数据

	//接受第二个输入序列的算法

}




//10.5.3 算法命名规范
void Fun_Algorithm_Naming_Conventions()
{
	//vector<int> vec = { 0,1,2,3,4,5,6,5,6,7,8,9 };
	//一些算法使用重载形式传递一个谓词
	//sort(vec.begin(), vec.end());
	//auto iter1 = unique(vec.begin(), vec.end());
	//vec.erase(iter1, vec.end());
	//printitem(vec);
	//auto iter2 = unique(vec.begin(), vec.end(), [](int num1, int num2) {return num1 == num2; });
	//vec.erase(iter2, vec.end());
	//printitem(vec);


	//_if版本的算法
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//auto iter1 = find(vec.begin(), vec.end(), 5);
	//auto iter2 = find_if(vec.begin(), vec.end(), [](int val) {return val == 5; });
	//cout << *iter1 << "   " << *iter2 << endl;
	
	//区分拷贝元素的版本和不拷贝的版本
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//reverse(vec.begin(), vec.end());
	//printitem(vec);
	//vector<int> vec2(vec.size());
	//reverse_copy(vec.begin(), vec.end(),vec2.begin());
	//printitem(vec2);

	//一些算法同时提供_copy和_if版本，这些版本接受一个目的为止迭代器和一个谓词：
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//printitem(vec);
	////移除奇数元素，返回一个迭代器指向偶数元素后一个元素的位置
	//auto iter = remove_if(vec.begin(), vec.end(), [](int i){return i % 2 == 1; });  
	//vec.erase(iter, vec.end());
	//printitem(vec);
	//vector<int> vec3;
	////拷贝偶数元素到vec3,vec保持不变
	//remove_copy_if(vec.begin(), vec.end(), back_inserter(vec3), [](int i) {return i % 2 == 1; }); 
	//printitem(vec);
	//printitem(vec3);

	//ex10.41
	//vector<int> vec = { 0,1,2,3,4,5,6,7,8,9 };
	//vector<int> vec2;
	////（1）把输入序列里面5替换成6
	//replace(vec.begin(), vec.end(), 5, 6);
	//printitem(vec)
	////（2）满足pred的元素，替换成6
	//replace_if(vec.begin(), vec.end(), [](int i) {return i <= 5; }, 6);//满足pred的元素，替换成6
	//printitem(vec)
	////（3）vec中的5替换成6，然后拷贝到vec2中
	//replace_copy(vec.begin(), vec.end(), back_inserter(vec2), 5, 6);
	//printitem(vec2);
	////（4）满足pred的元素，替换成6,然后拷贝到vec2中
	//replace_copy_if(vec.begin(), vec.end(), back_inserter(vec2), [](int i) {return i <= 5; }, 6);
	//printitem(vec2);

}







int main()
{
	//10.5.1 5类迭代器
	//Fun_The_Five_Iterator_Categories();
	//10.5.2 算法形参模式
	//Fun_Algorithm_Parameter_Patterns();
	//10.5.3 算法命名规范
	Fun_Algorithm_Naming_Conventions();
	return 0;
}

