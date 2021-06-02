#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//1.文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2.文件存在，但没有数据
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空!" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3.文件存在，并且保存职工的所有数据
	int num = this->get_EmpNum();
	//cout << "职工数为：" << num << "位" << endl;
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << this->m_EmpArray[i]->m_id << " "
	//		<< this->m_EmpArray[i]->m_name << " "
	//		<< this->m_EmpArray[i]->m_deptID << endl;
	//}

}

int WorkerManager::isExist(int id)
{
	int index = -1;//员工不存在返回-1，否则返回员工在数组里的位置
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入想要修改的职工编号:" << endl;
		int id;
		cin >> id;
		int ret = this->isExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;
			
			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新的姓名：" << endl;
			cin >> newName;
			cout << "请输入新的岗位：" << endl
				 << "1.普通职工" << endl
				 << "2.经理" << endl
				 << "3.老板" << endl;
			cin >> dSelect;
			Worker* newWorker = NULL;
			switch (dSelect)
			{
			case 1:
				newWorker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				newWorker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				newWorker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = newWorker;
			cout << "修改成功!" << endl;
			this->save();

		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入查找方式:" << endl
			<< "1.按编号查找" << endl
			<< "2.按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入要查找的编号" << endl;
			int id;
			cin >> id;
			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入要查找的姓名" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_name == name)
				{
					cout << "查找成功，职工编号为" << this->m_EmpArray[i]->m_id
						<< "的员工的信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else {
			cout << "输入有误！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)//选择排序
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
				else {
					if (this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后结果为：" << endl;
		this->save();
		this->show_Emp();
	}
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
	}
}


void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出系统
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		//开辟新的空间
		Worker ** newSpace = new Worker* [newSize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i +1<< "个新职工的编号：" << endl;
			while (true)
			{
				cin >> id;
				if (isExist(id) != -1)
				{
					cout << "您输入的编号已经存在，请重新输入：" << endl;
				}
				else {
					break;
				}
			}
			cout << "请输入第" << i +1<< "个新职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该员工的岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		cout << "添加成功" << addNum << "名新员工" << endl;
		this->save();
	}
	else {
		cout << "输入有误!" << endl;
	}
	system("pause");//按任意键后清屏，回到主界面
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_name << " "
			<< this->m_EmpArray[i]->m_deptID << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id, dId;
	string name;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id, dId;
	string name;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *temp_Worker = NULL;
		switch (dId)
		{
		case 1:
			temp_Worker = new Employee(id, name, dId);
			break;
		case 2:
			temp_Worker = new Manager(id, name, dId);
			break;
		case 3:
			temp_Worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}
		this->m_EmpArray[index++] = temp_Worker;

	}
	ifs.close();
}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");//按任意键后清屏，回到主界面
	system("cls");
}

void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		int id = 0;
		cout << "请输入想删除的职工编号：" << endl;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i+1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，该员工编号不存在！" << endl;
		}
		
	}
	system("pause");
	system("cls");
}
