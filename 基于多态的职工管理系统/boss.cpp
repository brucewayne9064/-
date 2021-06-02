#include"boss.h"

Boss::Boss(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Boss::showInfo()
{
	cout << "职工编号为：" << this->m_id
		<< "\t职工的姓名为：" << this->m_name
		<< "\t职工的岗位为：" << this->getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{

	return string("老板");
}
