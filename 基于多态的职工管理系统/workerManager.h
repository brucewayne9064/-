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

	void Show_Menu();//չʾ�˵�

	void exitSystem();//�˳�ϵͳ

	void Add_Emp();//����Ա��

	void save();//�����ļ�

	int get_EmpNum();//ͳ���ļ��е�������

	void init_Emp();//���ļ�����������ʼ��m_EmpArray

	void show_Emp();//��ʾְ��

	void Del_Emp();//ɾ��ְ��

	int isExist(int id);////����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1

	void Mod_Emp();//�޸�ְ��

	void Find_Emp();//����ְ��

	void Sort_Emp();//ְ������

	void Clean_File();//����ļ�

	~WorkerManager();
public:
	//��¼ְ������
	int m_EmpNum;
	//ְ�������ָ��
	Worker** m_EmpArray;
	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};