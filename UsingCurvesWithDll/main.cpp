#include "stdafx.h"
#include "MemoryLeaksDetector.h"
#include "Tasks.h"


int main(int argc, char** argv)
{
	auto sOld = MemoryLeaksDetector::snapshot();

	srand((unsigned int)time(NULL));
	Tasks::getInstance().start();
	
	MemoryLeaksDetector::check(sOld);
	return 0;
}
