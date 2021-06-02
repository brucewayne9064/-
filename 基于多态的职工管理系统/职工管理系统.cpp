#include"workerManager.h"
#include<iostream>
using namespace std;
//#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"

int main(void)
{
	//多态测试
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三",1);
	//worker->showInfo();//利用了多态
	//delete worker;

	//worker = new Manager(2,"李四",2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工	
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://职工排序
			wm.Sort_Emp();
			break;
		case 7://清空职工
			wm.Clean_File();
			break;
		default:
			system("cls");//输入其他的直接清空屏幕(数字int)
			break;
		}
	}
	return 0;
}