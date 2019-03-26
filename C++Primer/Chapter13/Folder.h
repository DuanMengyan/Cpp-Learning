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
	
	//�������캯��
	Folder(const Folder &f)
	{
		name = f.name + "_copy";
		set_m = f.set_m;
		add_to_Messages(f);
	}

	//�������������
	Folder& operator=(const Folder&);

	~Folder();

	//��ӡ��ǰ�ļ��е�����
	void print_name();

	//��ӡ�ļ����а�������Ϣ
	void print_messages();

private:
	string name;
	set<Message*> set_m;

	//�����Ϣ�ļ�
	void addMsg(Message*);

	//ɾ����Ϣ�ļ�
	void remMsg(Message*);

	//��folder��ӵ���Ϣ�ļ���folder_set��
	void add_to_Messages(const Folder&);

	//�Ӱ�������Ϣ�ļ���folder_set��ɾ��
	void remove_from_Messages();
};



#endif // !FOLDER_H
