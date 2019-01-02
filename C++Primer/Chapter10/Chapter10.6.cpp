#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter10.6.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年1月2日 星期三
> Last edited time: 2019年1月2日 星期三
> Topic:C++Primer Chapter10.6 特定容器算法
************************************************************************/

#include "fun.h"
#include "header_include.h"
#include "Sales_data.h"
//#include "Sales_item.h"


using namespace std;

//Chapter10.6 特定容器算法
void Fun_Container_Specific_Algorithms()
{
	//对于list和forward——list，应该优先使用成员函数版本的算法而不是通用算法
	//list<int> lst1 = { 0,2,4,6,8 };
	//list<int> lst2 = { 1,3,5,7,9 };
	////lst1.merge(lst2);
	////printitem(lst1);
	//lst1.merge(lst2, [](int i, int j) {return i < j; });
	//printitem(lst1);

	//splice成员，是链表数据结构所特有的
	////插入到list的首元素前
	//list<int> lst1 = { 0,2,4,6,8 };
	//list<int> lst2 = { 1,3,5,7,9 };
	//lst1.splice(lst1.begin(), lst2);
	//printitem(lst1);
	////插入到前向列表的首前元素后
	//forward_list<int> lst1 = { 0,2,4,6,8 };
	//forward_list<int> lst2 = { 1,3,5,7,9 };
	//lst1.splice_after(lst1.before_begin(), lst2);
	//for (auto str : lst1)
	//{
	//	cout << str << "   ";
	//}
	//cout << endl << "=========================" << endl;

	//链表特有的操作会改变容器
	//链表特有版本的算法会改变底层容器


	//ex10.42
	//list<string> str_lst = { "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	////按照字典序排序
	//str_lst.sort();
	//printitem(str_lst);
	////删除相同值元素
	//str_lst.unique();
	//printitem(str_lst);

}




int main()
{
	//Chapter10.6 特定容器算法
	Fun_Container_Specific_Algorithms();

	return 0;
}