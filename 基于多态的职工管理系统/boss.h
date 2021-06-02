#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"

class Boss : public Worker
{
public:
	Boss(int id, string name, int d_id);
	virtual void showInfo();
	virtual string getDeptName();

}; 
