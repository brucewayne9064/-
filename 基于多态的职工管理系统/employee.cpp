#include"employee.h"

Employee::Employee(int id, string name, int d_id)
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptID = d_id;
}

void Employee::showInfo()
{
	cout << "职工编号为：" << this->m_id
		<< "\t职工的姓名为：" << this->m_name
		<< "\t职工的岗位为：" << this->getDeptName()
		<< "\t岗位职责：完成经理布置的任务" << endl;
}

string Employee::getDeptName()
{

	return string("普通员工");
}
