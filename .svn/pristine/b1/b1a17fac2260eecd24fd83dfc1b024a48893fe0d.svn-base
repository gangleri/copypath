// CopyPathExt.h : Declaration of the CCopyPathExt

#ifndef __COPYPATHSHLEXT_H_
#define __COPYPATHSHLEXT_H_

#include <shlobj.h>
#include <comdef.h>
#include "resource.h"       // main symbols
#include "CopyPath_i.h"


class ATL_NO_VTABLE CCopyPathExt :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCopyPathExt, &CLSID_CopyPathExt>,
	public IShellExtInit,
    public IContextMenu
{
public:
	CCopyPathExt() { }

	DECLARE_REGISTRY_RESOURCEID(IDR_COPYPATHEXT)

	BEGIN_COM_MAP(CCopyPathExt)
		COM_INTERFACE_ENTRY(IShellExtInit)
		COM_INTERFACE_ENTRY(IContextMenu)
	END_COM_MAP()

public:
	// IShellExtInit
    STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);

    // IContextMenu
    STDMETHODIMP GetCommandString(UINT, UINT, UINT*, LPSTR, UINT);
    STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
    STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);

protected:
    TCHAR m_szFile [MAX_PATH];

};

#endif //__COPYPATHSHLEXT_H_