// OVLibrary.h

#ifndef __OVLibrary_h
#define __OVLibrary_h

// as a dynamically-loadable library (be it .so, .DLL, .dylib or .bundle),
// we only need to export these three functions

// extern "C" unsigned int OVGetLibraryVersion();
// extern "C" int OVInitializeLibrary(OVDictionary* globalPref, OVService* srv, 
//    const char* libPath, const char *seperator);
// extern "C" OVModule *OVGetModuleFromLibrary(int idx);


// wrapper macro for libraries that have exactly only one OVModule (IM/OF)
#define OVSINGLEMODULEWRAPPER(classname) \
    extern "C" unsigned int OVGetLibraryVersion() { return OVVERSION; } \
    extern "C" int OVInitializeLibrary(OVDictionary*, OVService*, \
        const char*, const char*) { return 1; } \
    extern "C" OVModule *OVGetModuleFromLibrary(int idx) \
    { \
        return (idx==0) ? new classname : NULL; \
    }

// below are used for most OV Loader implementations, not needed by any 
// loadable library

typedef unsigned int _OVGetLibraryVersion_t();
typedef int _OVInitializeLibrary_t(OVDictionary*, OVService*, const char*,
    const char*);
typedef OVModule* _OVGetModuleFromLibrary_t(int);

struct OVLoadedLibrary
{
    OVLoadedLibrary(_OVInitializeLibrary_t *i, _OVGetModuleFromLibrary_t *m) :
        initialize(i), getModule(m) {}

    _OVInitializeLibrary_t *initialize;
    _OVGetModuleFromLibrary_t *getModule;
};

#endif
