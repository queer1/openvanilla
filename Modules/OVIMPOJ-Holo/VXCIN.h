// VXCIN.h

#ifndef __VXCIN_h
#define __VXCIN_h

#include <Cocoa/Cocoa.h>
#include <OpenVanilla/OpenVanilla.h>
#include <OpenVanilla/OVUtility.h>
#include "OVDeprecated.h"

OVEncoding VXEncodingMapper(const char *s);

class VXCIN
{
public:
    VXCIN();
    ~VXCIN();
    void read(char *fname, OVEncoding enc=ovEncodingUTF8, int shiftselkey=0);
    NSArray* find(char *key);
    NSString* getKey(char keycode);

    int selKeyOrder(char keycode);      // -1 if none
    char* selKey() { return selkey; }
    int name(char *locale, void *s, OVEncoding *enc);
    int isEndKey(char c);
    
protected:
    NSMutableDictionary* keytable;
    NSMutableDictionary* chartable;
    char selkey[32];
    char endkey[32];
    char ename[256];
    NSString* cname;
    
    OVEncoding encoding;
};

#endif