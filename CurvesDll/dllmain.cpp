// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        std::cout << "CurveDll is attached to process\n";
        break;
    }
    case DLL_THREAD_ATTACH:
    {
        std::cout << "CurveDll is attached to thread\n";
        break;
    }
    case DLL_THREAD_DETACH:
    {
        std::cout << "CurveDll is detached from thread\n";
        break;
    }
    case DLL_PROCESS_DETACH:
    {
        std::cout << "CurveDll is detached from process\n";
        break;
    }
    }
    return TRUE;
}

