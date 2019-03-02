#pragma once



#ifndef MESSAGE_H
#define MESSAGE_H

#include "header_include.h"
#include "Folder.h"

using namespace std;

class Message
{
	friend class Folder;
	friend void swap(Message &, Message &);
public:
	
	explicit Message(const string &str = "") :contents(str) { };
	
	//�������캯��
	Message(const Message&);

	//������ֵ�����
	Message& operator=(const Message&);
	
	~Message();

	//
	void save_to_Folder(Folder&);

	void remove_from_Folder(Folder&);

	//��ӡ��Ϣ����
	void print_message();

	//��ӡ������ǰ��Ϣ���ļ���
	void print_folders();

private:
	string contents;				//ʵ����Ϣ�ı�
	set<Folder*> folders;			//������Message��Folder

	//�������캯����������ֵ�����������������ʹ�õĹ��ߺ���
	
	//����Message��ӵ�ָ�������Folder��
	void save_to_Folders(const Message&);
	//��folders�е�ÿ��Folder��ɾ����Message
	void remove_from_Folders();

};


#endif // !MESSAGE_H
