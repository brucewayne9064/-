#include"manager.h"

Manager::Manager(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Manager::showInfo()
{
	cout << "职工编号为：" << this->m_id
		<< "\t职工的姓名为：" << this->m_name
		<< "\t职工的岗位为：" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDeptName()
{

	return string("经理");
}
