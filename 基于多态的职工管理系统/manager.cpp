#include"manager.h"

Manager::Manager(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Manager::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_id
		<< "\tְ��������Ϊ��" << this->m_name
		<< "\tְ���ĸ�λΪ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << endl;
}

string Manager::getDeptName()
{

	return string("����");
}
