

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat Oct 10 21:55:52 2009
 */
/* Compiler settings for .\CopyPath.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __CopyPath_i_h__
#define __CopyPath_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICopyPathExt_FWD_DEFINED__
#define __ICopyPathExt_FWD_DEFINED__
typedef interface ICopyPathExt ICopyPathExt;
#endif 	/* __ICopyPathExt_FWD_DEFINED__ */


#ifndef __CopyPathExt_FWD_DEFINED__
#define __CopyPathExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class CopyPathExt CopyPathExt;
#else
typedef struct CopyPathExt CopyPathExt;
#endif /* __cplusplus */

#endif 	/* __CopyPathExt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICopyPathExt_INTERFACE_DEFINED__
#define __ICopyPathExt_INTERFACE_DEFINED__

/* interface ICopyPathExt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICopyPathExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87145C87-2230-4A80-A922-21FC3C823A3C")
    ICopyPathExt : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICopyPathExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICopyPathExt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICopyPathExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICopyPathExt * This);
        
        END_INTERFACE
    } ICopyPathExtVtbl;

    interface ICopyPathExt
    {
        CONST_VTBL struct ICopyPathExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICopyPathExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICopyPathExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICopyPathExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICopyPathExt_INTERFACE_DEFINED__ */



#ifndef __CopyPathLib_LIBRARY_DEFINED__
#define __CopyPathLib_LIBRARY_DEFINED__

/* library CopyPathLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_CopyPathLib;

EXTERN_C const CLSID CLSID_CopyPathExt;

#ifdef __cplusplus

class DECLSPEC_UUID("41EB7708-39AD-418A-90A1-5126C5BAFCE0")
CopyPathExt;
#endif
#endif /* __CopyPathLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


