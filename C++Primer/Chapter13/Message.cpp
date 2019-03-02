#include "Message.h"

//�������캯��
Message::Message(const Message &m)
{
	save_to_Folders(m);			//������Ϣ��ӵ�ָ��m��Folder��
}

//������ֵ�����
Message & Message::operator=(const Message &rhs)
{
	//ͨ����ɾ��ָ���ٲ��������������Ը�ֵ���
	remove_from_Folders();			//�������е�Folder
	contents = rhs.contents;		//��rhs������Ϣ����
	folders = rhs.folders;			//��rhs����Folderָ��
	save_to_Folders(rhs);			//����Message��ӵ���ЩFolder��
	return *this;
}

//��������
Message::~Message()
{
	remove_from_Folders();
}

//����Ϣ������ָ�����ļ��У�
void Message::save_to_Folder(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove_from_Folder(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::print_message()
{
	cout << contents << endl;
}

void Message::print_folders()
{
	for (auto f : folders)
		cout << f->name << " ==== ";
	cout << endl;
}


//����Message��ӵ�ָ�������Folder��
void Message::save_to_Folders(const Message &m)
{
	for (auto f : m.folders)		//��ÿ������m��Folder
	{								
		f->addMsg(this);			//���Folder���һ��ָ��Message��ָ��
	}
}

//��folders�е�ÿ��Folder��ɾ����Message
void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;		
	//��ÿ����Ϣ��ָ�������ԭ��������Folder��ɾ��
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	
	//����contents��Folderָ��set
	swap(lhs.contents, rhs.contents);	
	swap(lhs.folders, rhs.folders);

	//��ÿ��Message��ָ����ӵ�������Folders��
	lhs.save_to_Folders(lhs);
	rhs.save_to_Folders(rhs);
}
