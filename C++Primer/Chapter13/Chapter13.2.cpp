#pragma once
#pragma execution_character_set("utf-8")


/*************************************************************************
> File Name: Chapter13.2.cpp
> Author: DMY
> Mail: dmy_email@163.com
> Created Time: 2019��2��23�� ������
> Last edited time: 2019��2��26�� ���ڶ�
> Topic:C++Primer Chapter13.2 �������ƺ���Դ����
************************************************************************/

#include "header_include.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "HasPtr.h"


using namespace std;


//Chapter13.2.1 ��Ϊ��ֵ����
void Fun_Classes_That_Act_Like_Values()
{
	//Ϊ��ʵ����ֵ��Ϊ��HasPtr��Ҫ��
	//1.����һ���������캯�������string�Ŀ����������ǿ���ָ��
	//2.����һ�������������ͷ�string
	//3.����һ��������ֵ��������ͷŶ���ǰ��string�������Ҳ�������󿽱�string

	//��ֵ������ֵ�������������������������Դ֮ǰ�������Ҳ��������
	//1.�����һ����������������ֵ����������ܹ���ȷ����
	//2.�������ֵ�������������������Ϳ������캯���Ĺ���
	//�Ƚ��Ҳ�������󿽱���һ���ֲ���ʱ�����У�������ɺ�������������������г�Ա���ǰ�ȫ���ˡ�
	//һ���������������Դ�����٣���ֻʣ�½����ݴ���ʱ���󿽱�������������ĳ�Ա����

	//ex13.23
	//������ֵ�����������д��������������������Դ֮ǰ�������Ҳ��������
	
	//ex13.24
	//���û�ж��������������������ڴ�й©���ϳɰ汾��������������̬�ڴ�
	//���û�ж��忽�����캯��������ps�Ŀ����ͻ���ָ�뱾��Ŀ�����Υ����ֵ��Ϊ�����һ����

	//ex13.25
	//StrBlob��Ա������ָ�룬����ʹ�úϳ�������������̬�ڴ�
	//�������캯���Ϳ�����ֵ���������ӦΪ�Լ���̬�����ڴ棬�����Ǻ��Ҳ����������

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





//Chapter13.2.2 ��Ϊ��ָ�����
void Fun_Defining_Classes_That_Act_Like_Pointers()
{
	//��һ����չ������ָ�����Ϊ����õķ�����ʹ��shared_ptr���������е���Դ

	//���ü�������ʹ��shared_ptr������Լ������ü���
	//�������������ڶ�̬�ڴ��У�������һ������ʱ������Ҳ����һ���µļ�������
	//��������ֵ����ʱ�����ǿ���ָ���������ָ�롣

	//����һ��ʹ�����ü�������
	//��ָ��Ŀ�����Ա���۸ġ����ü���

	//ex13.27
	
	//ex13.28



}





int main()
{

	return 0;
}
