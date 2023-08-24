#pragma once
#include "stdafx.h"


class Tasks
{
public:
	static Tasks& getInstance();

	void start();

private:
	Tasks();
	Tasks(Tasks&&) = delete;
	~Tasks();

	Tasks& operator=(const Tasks&) = delete;
};

