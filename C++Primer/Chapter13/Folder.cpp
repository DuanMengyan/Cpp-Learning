#include "Folder.h"


Folder &Folder::operator=(const Folder &f)
{
	remove_from_Messages();
	
	name = f.name+"_copy";
	set_m = f.set_m;
	
	add_to_Messages(*this);
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

//�����Ϣ
void Folder::addMsg(Message *m)
{
	set_m.insert(m);
}

//ɾ����Ϣ�ļ�
void Folder::remMsg(Message *m)
{
	set_m.erase(m);
}

//��folder��ӵ���Ϣ�ļ���folder_set��
void Folder::add_to_Messages(const Folder& f)
{
	for (auto m : f.set_m)
		m->save_to_Folder(*this);
}

//�Ӱ�������Ϣ�ļ���folder_set��ɾ��
void Folder::remove_from_Messages()
{
	for (auto m : set_m)
	{
		m->folders.erase(this);
	}			
}


void Folder::print_name()
{
	cout << name << endl;
}

//��ӡfolder��������Ϣ�ļ�
void Folder::print_messages()
{
	for (auto m : set_m)
	{
		cout << m->contents << endl;
	}
}



