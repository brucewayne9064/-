#include"boss.h"

Boss::Boss(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Boss::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_id
		<< "\tְ��������Ϊ��" << this->m_name
		<< "\tְ���ĸ�λΪ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{

	return string("�ϰ�");
}
