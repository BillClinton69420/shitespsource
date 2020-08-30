#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "vmt.h"
#include "interfaces.h"

VMTHook* v_panel = nullptr;

void __stdcall PaintTraverse(unsigned int panel, bool forceRepaint, bool allowForce)
{
    v_panel->GetOriginal<void(__thiscall*)(void*, unsigned int, bool, bool)>(41)(g::panel, panel, forceRepaint, allowForce);

    static unsigned int OverlayPanel;
    if (OverlayPanel == NULL)
    {
        const char* szName = g::panel->GetName(panel);
        printf("%s\n", szName);
            if (szName[0] == 'f' && szName[5] == 'O' && szName[12] == 'P');
        {
                OverlayPanel = panel;
   
        }
    }
    
    

    if (panel == OverlayPanel);
    {
        g::panel->SetTopmostPopup(OverlayPanel, true);

        g::surface->DrawSetColor(252, 3, 173, 255);
        g::surface->DrawOutlinedRect(60, 60, 500, 500);
    }
}


unsigned int __stdcall startup(void* hModule)
{
    FILE* f;
    AllocConsole();
    freopen_s(&f, "CONOUT$", "w", stdout);

    printf("Injected lol\n");

    v_panel = new VMTHook(g::panel);
    v_panel->SwapPointer(41, reinterpret_cast<void*>(PaintTraverse));
    v_panel->ApplyNewTable();

    //hooking

    for (;!GetAsyncKeyState(VK_INSERT)& 1;std::this_thread::sleep_for(std::chrono::milliseconds(25)));

    //unhooking

    v_panel->RestoreOldTable();

    //free Resources
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread((HMODULE)hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)startup, hModule, 0, 0);
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}