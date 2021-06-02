#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager 
{
public:
	WorkerManager();

	void Show_Menu();//展示菜单

	void exitSystem();//退出系统

	void Add_Emp();//增加员工

	void save();//保存文件

	int get_EmpNum();//统计文件中的人数；

	void init_Emp();//把文件读进来，初始化m_EmpArray

	void show_Emp();//显示职工

	void Del_Emp();//删除职工

	int isExist(int id);////按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1

	void Mod_Emp();//修改职工

	void Find_Emp();//查找职工

	void Sort_Emp();//职工排序

	void Clean_File();//清空文件

	~WorkerManager();
public:
	//记录职工人数
	int m_EmpNum;
	//职工数组的指针
	Worker** m_EmpArray;
	//标志文件是否为空
	bool m_FileIsEmpty;

};