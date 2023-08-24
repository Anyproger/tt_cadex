#pragma once
#ifdef _DEBUG

#include "windows.h"
#define _CRTDBG_MAP_ALLOC //to get more details
#include <stdlib.h>  

#endif // _DEBUG

#include <crtdbg.h>   //for malloc and free


namespace MemoryLeaksDetector
{
    _CrtMemState snapshot();
    void check(_CrtMemState& sOld);
}
