#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019年2月23日 星期六
> Last edited time: 2019年2月26日 星期二
> Topic:C++Primer Chapter13.2 拷贝控制和资源管理
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "HasPtr.h"


using namespace std;


//Chapter13.2.1 行为像值的类
void Fun_Classes_That_Act_Like_Values()
{
	//为了实现类值行为，HasPtr需要：
	//1.定义一个拷贝构造函数，完成string的拷贝，而不是拷贝指针
	//2.定义一个析构函数来释放string
	//3.定义一个拷贝赋值运算符来释放对象当前的string，并从右侧运算对象拷贝string

	//类值拷贝赋值运算符，在销毁左侧运算对象资源之前，拷贝右侧运算对象
	//1.如果将一个对象赋予它自身，赋值运算符必须能够正确工作
	//2.大多数赋值运算符组合了析构函数和拷贝构造函数的工作
	//先将右侧运算对象拷贝到一个局部临时对象中，拷贝完成后，销毁左侧运算对象的现有成员就是安全的了。
	//一旦左侧运算对象的资源被销毁，就只剩下将数据从临时对象拷贝到左侧运算对象的成员中了

	//ex13.23
	//拷贝赋值运算符函数编写，在销毁左侧运算对象资源之前，拷贝右侧运算对象
	
	//ex13.24
	//如果没有定义析构函数，则会造成内存泄漏，合成版本析构函数不管理动态内存
	//如果没有定义拷贝构造函数，对于ps的拷贝就会是指针本身的拷贝（违反类值行为规则第一条）

	//ex13.25
	//StrBlob成员是智能指针，可以使用合成析构函数管理动态内存
	//拷贝构造函数和拷贝赋值运算符函数应为自己动态分配内存，而不是和右侧运算对象共享

	//ex13.26
	
}


//ex13.28
class TreeNode
{
public:
	TreeNode() :value(string()), count(new int(1)), left(nullptr), right(nullptr) {};
	TreeNode(const TreeNode &tn):value(tn.value),count(tn.count),left(tn.left),right(tn.right)
	{
		++*count;
	}
	TreeNode& operator=(const TreeNode &tn)
	{
		++*tn.count;
		if (--*count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
		value = tn.value;
		count = tn.count;
		left = tn.left;
		right = tn.right;
		return *this;
	}
	~TreeNode()
	{
		if (--*count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
	}

private:
	string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};


class BinStrTree
{
public:
	BinStrTree() :root(new TreeNode()) {};
	BinStrTree(const BinStrTree &bst) :root(new TreeNode(*bst.root)) {};
	BinStrTree& operator=(const BinStrTree &bst)
	{
		TreeNode *new_root = new TreeNode(*bst.root);
		delete root;
		root = new_root;
		return *this;
	}

	~BinStrTree()
	{
		delete root;
	}

private:
	TreeNode *root;
};





//Chapter13.2.2 行为象指针的类
void Fun_Defining_Classes_That_Act_Like_Pointers()
{
	//令一个类展现类似指针的行为，最好的方法是使用shared_ptr来管理类中的资源

	//引用计数，不使用shared_ptr，设计自己的引用计数
	//将计数器保存在动态内存中，当创建一个对象时，我们也分配一个新的计数器。
	//当拷贝或赋值对象时，我们拷贝指向计数器的指针。

	//定义一个使用引用计数的类
	//类指针的拷贝成员“篡改”引用计数

	//ex13.27
	
	//ex13.28



}





int main()
{

	return 0;
}
