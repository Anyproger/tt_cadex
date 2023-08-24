#include "MemoryLeaksDetector.h"


_CrtMemState MemoryLeaksDetector::snapshot()
{
    _CrtMemState sOld; 
#ifdef _DEBUG
    _CrtMemCheckpoint(&sOld); //take a snapshot
#endif // _DEBUG
    return sOld;
}

void MemoryLeaksDetector::check(_CrtMemState& sOld)
{
#ifdef _DEBUG
    _CrtMemState sNew;
    _CrtMemCheckpoint(&sNew); //take a snapshot 
    _CrtMemState sDiff;
    if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
    {
        OutputDebugString(L"-----------_CrtMemDumpStatistics ---------");
        _CrtMemDumpStatistics(&sDiff);
        OutputDebugString(L"-----------_CrtMemDumpAllObjectsSince ---------");
        _CrtMemDumpAllObjectsSince(&sOld);
        OutputDebugString(L"-----------_CrtDumpMemoryLeaks ---------");
        _CrtDumpMemoryLeaks();
    }
#endif // _DEBUG
}
