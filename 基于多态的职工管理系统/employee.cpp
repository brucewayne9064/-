#include"employee.h"

Employee::Employee(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Employee::showInfo()
{
	cout << "ְ�����Ϊ��" << this->m_id
		<< "\tְ��������Ϊ��" << this->m_name
		<< "\tְ���ĸ�λΪ��" << this->getDeptName()
		<< "\t��λְ����ɾ����õ�����" << endl;
}

string Employee::getDeptName()
{

	return string("��ͨԱ��");
}
