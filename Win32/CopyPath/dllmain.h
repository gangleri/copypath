// dllmain.h : Declaration of module class.

class CCopyPathModule : public CAtlDllModuleT< CCopyPathModule >
{
public :
	DECLARE_LIBID(LIBID_CopyPathLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COPYPATHEXT, "{453DB888-3B7A-4B72-A6B0-B1C12B06BF6E}")
};

extern class CCopyPathModule _AtlModule;
