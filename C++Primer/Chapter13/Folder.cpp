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

//添加消息
void Folder::addMsg(Message *m)
{
	set_m.insert(m);
}

//删除消息文件
void Folder::remMsg(Message *m)
{
	set_m.erase(m);
}

//把folder添加到消息文件的folder_set中
void Folder::add_to_Messages(const Folder& f)
{
	for (auto m : f.set_m)
		m->save_to_Folder(*this);
}

//从包含的消息文件的folder_set中删除
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

//打印folder包含的消息文件
void Folder::print_messages()
{
	for (auto m : set_m)
	{
		cout << m->contents << endl;
	}
}



