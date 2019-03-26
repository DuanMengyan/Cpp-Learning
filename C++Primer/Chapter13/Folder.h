#pragma once


#ifndef FOLDER_H
#define FOLDER_H

#include "header_include.h"
#include "Message.h"

using namespace std;

class Folder
{
	friend class Message;

public:
	explicit Folder(const string &str = "") :name(str) { };
	
	//拷贝构造函数
	Folder(const Folder &f)
	{
		name = f.name + "_copy";
		set_m = f.set_m;
		add_to_Messages(f);
	}

	//拷贝构造运算符
	Folder& operator=(const Folder&);

	~Folder();

	//打印当前文件夹的名字
	void print_name();

	//打印文件夹中包含的信息
	void print_messages();

private:
	string name;
	set<Message*> set_m;

	//添加消息文件
	void addMsg(Message*);

	//删除消息文件
	void remMsg(Message*);

	//把folder添加到消息文件的folder_set中
	void add_to_Messages(const Folder&);

	//从包含的消息文件的folder_set中删除
	void remove_from_Messages();
};



#endif // !FOLDER_H
