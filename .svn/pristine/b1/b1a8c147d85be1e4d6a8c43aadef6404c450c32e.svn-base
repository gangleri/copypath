// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "CopyPath_i.h"
#include "dllmain.h"
#include <initguid.h>
#include "CopyPathExt.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_CopyPathExt, CCopyPathExt)
END_OBJECT_MAP()

// DLL Entry Point
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_CopyPathLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    // ok
}

// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
	if ( 0 == (GetVersion() & 0x80000000UL) )
        {
        CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE,
                          _T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
                          KEY_SET_VALUE );

        if ( ERROR_SUCCESS != lRet )
            return E_ACCESSDENIED;

        lRet = reg.SetStringValue ( _T("CopyPathExt extension"), 
                              _T("{41EB7708-39AD-418A-90A1-5126C5BAFCE0}") );

        if ( ERROR_SUCCESS != lRet )
            return E_ACCESSDENIED;
        }

    // registers object, typelib and all interfaces in typelib
    return _Module.RegisterServer(FALSE);
    //HRESULT hr = _AtlModule.DllRegisterServer();
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	if ( 0 == (GetVersion() & 0x80000000UL) )
        {
        CRegKey reg;
        LONG    lRet;

        lRet = reg.Open ( HKEY_LOCAL_MACHINE,
                          _T("Software\\Microsoft\\Windows\\CurrentVersion\\Shell Extensions\\Approved"),
                          KEY_SET_VALUE );

        if ( ERROR_SUCCESS == lRet )
            {
            lRet = reg.DeleteValue ( _T("{41EB7708-39AD-418A-90A1-5126C5BAFCE0}") );
            }
        }

    /*HRESULT hr = _AtlModule.DllUnregisterServer();
	return hr; */
	return _Module.UnregisterServer(FALSE);;
}

