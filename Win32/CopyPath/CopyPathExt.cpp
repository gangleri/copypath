// CopyPathExt.cpp : Implementation of CCopyPathExt

#include "stdafx.h"
#include "resource.h"
#include "WinNetWk.h"
#include "WinError.h"
#include "CopyPathExt.h"


STDMETHODIMP CCopyPathExt::Initialize ( LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID )
{
	FORMATETC fmt = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stg = { TYMED_HGLOBAL };
	HDROP     hDrop;

    // Look for CF_HDROP data in the data object.
    if ( FAILED( pDataObj->GetData ( &fmt, &stg ) ))
	{
        // Nope! Return an "invalid argument" error back to Explorer.
        return E_INVALIDARG;
	}

    // Get a pointer to the actual data.
    hDrop = (HDROP) GlobalLock ( stg.hGlobal );

    // Make sure it worked.
    if ( NULL == hDrop )
	{
        return E_INVALIDARG;
	}

    // Sanity check - make sure there is at least one filename.
	UINT uNumFiles = DragQueryFile ( hDrop, 0xFFFFFFFF, NULL, 0 );
	HRESULT hr = S_OK;

    if ( 0 == uNumFiles )
	{
        GlobalUnlock ( stg.hGlobal );
        ReleaseStgMedium ( &stg );
        return E_INVALIDARG;
	}

    // Get the name of the first file and store it in our member variable m_szFile.
    if ( 0 == DragQueryFile ( hDrop, 0, m_szFile, MAX_PATH ) )
	{
        hr = E_INVALIDARG;
	}

    GlobalUnlock ( stg.hGlobal );
    ReleaseStgMedium ( &stg );

    return hr;
}

STDMETHODIMP CCopyPathExt::QueryContextMenu ( HMENU hmenu, UINT uMenuIndex, UINT uidFirstCmd,UINT uidLastCmd, UINT uFlags )
{
    // If the flags include CMF_DEFAULTONLY then we shouldn't do anything.
    if ( uFlags & CMF_DEFAULTONLY )
	{
        return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 0 );
	}

    InsertMenu ( hmenu, uMenuIndex, MF_BYPOSITION, uidFirstCmd, _T("Copy Path") );

    return MAKE_HRESULT ( SEVERITY_SUCCESS, FACILITY_NULL, 1 );
}

STDMETHODIMP CCopyPathExt::GetCommandString ( UINT idCmd, UINT uFlags, UINT* pwReserved, LPSTR pszName, UINT cchMax )
{
	USES_CONVERSION;

    // Check idCmd, it must be 0 since we have only one menu item.
    if ( 0 != idCmd )
        return E_INVALIDARG;

    // If Explorer is asking for a help string, copy our string into the
    // supplied buffer.
    if ( uFlags & GCS_HELPTEXT )
	{
        LPCTSTR szText = _T("This will copy the path of the item to the clipboard. If the item exits on a network drive the UNC path will be resolved");

        if ( uFlags & GCS_UNICODE )
		{
            // We need to cast pszName to a Unicode string, and then use the
            // Unicode string copy API.
            lstrcpynW ( (LPWSTR) pszName, T2CW(szText), cchMax );
		}
        else
		{
            // Use the ANSI string copy API to return the help string.
            lstrcpynA ( pszName, T2CA(szText), cchMax );
		}

        return S_OK;
	}

    return E_INVALIDARG;
}

STDMETHODIMP CCopyPathExt::InvokeCommand ( LPCMINVOKECOMMANDINFO pCmdInfo )
{
    // If lpVerb really points to a string, ignore this function call and bail out.
    if ( 0 != HIWORD( pCmdInfo->lpVerb ) )
	{
        return E_INVALIDARG;
	}

    // Get the command index - the only valid one is 0.
    switch ( LOWORD( pCmdInfo->lpVerb) )
	{
		case 0:
			{			
				// check if the path is to a mapped drive
				TCHAR szMsg [MAX_PATH + 32];
				UNIVERSAL_NAME_INFO *puinfo;
				char buf2[300];
				DWORD size;
				size = MAX_PATH + 32;

				if (WNetGetUniversalName(m_szFile, UNIVERSAL_NAME_INFO_LEVEL, buf2, &size) == NO_ERROR)
				{
					// it's a network drive so lets get the UNC path
					puinfo = (UNIVERSAL_NAME_INFO*)buf2;
					wsprintf ( szMsg, _T("%s"), puinfo->lpUniversalName );
					//strncpy_s<size>(szMsg, puinfo->lpUniversalName, size);
				}
				else
				{
					wsprintf ( szMsg, _T("%s"), m_szFile );
					//strncpy_s<size>(szMsg, m_szFile, size);
				}

				if (!OpenClipboard(pCmdInfo->hwnd))
				{
					return S_OK;
				}

				// copy path to clipboard
				EmptyClipboard();

				HGLOBAL hCom;
				if (!(hCom = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, MAX_PATH + 32)))
				{
					return S_OK;
				}

				LPVOID pCom;
				if (!(pCom = GlobalLock(hCom)))
				{
					GlobalFree(hCom);
					return S_OK;
				}

				CopyMemory(pCom, szMsg, size);
				SetClipboardData(CF_TEXT, hCom);

				GlobalUnlock(hCom);
				CloseClipboard();

				return S_OK;
			}
        break;

        default:
            return E_INVALIDARG;
        break;
	}
}