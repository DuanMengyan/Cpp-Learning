#pragma once
#pragma execution_character_set("utf-8")

/*************************************************************************
> File Name: Chapter9.1.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2018年10月29日 星期一
> Last edited time: 2018年10月29日 星期一
> Topic:C++Primer Chapter9.1 顺序容器概述
************************************************************************/

#include "header_include.h"

using namespace std;


//9.1 顺序容器概述
void Fun_Overview_of_the_Sequential_Containers()
{
	//确定选用哪种容器
	//通常vector是最好的选择
	//如果有很多小元素，且空间的额外开销很重要，则不要使用list或forward_list
	//如果程序要求随机访问元素，则应选择vector或deque
	//如果要求在容器中间插入或删除元素，则应使用list或forward_list
	//如果要求在容器头尾插入或删除元素，但不会在中间位置进行插入或删除操作，则使用deque
	//如果程序只有在读取输入时才需要在容器中间位置插入元素，随后需要随机访问元素，则
	//——————首先，确定是否真的需要在容器中间位置添加元素。
	//		当处理输入数据时，通常可以很容易地向vector追加数据，然后调用标准库的sort函数进行排序
	//——————如果必须在中间位置添加元素，考虑再输入阶段使用list，输入完成后将list内容拷贝到一个vector中。		
	//
	//一般来说：应用占主导地位的操作决定了容器的类型
	//
	//如果不确定选用哪种容器，可以只使用vector和list的公共操作：迭代器，避免随机访问
	
	//ex9.1
	//(a)list
	//(b)deque
	//(c)vector

}

int main()
{
	//9.1 顺序容器概述
	Fun_Overview_of_the_Sequential_Containers();
	return 0;
}