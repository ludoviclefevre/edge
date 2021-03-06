#include "edge.h"

BOOL debugMode;
BOOL enableScriptIgnoreAttribute;
BOOL enableMarshalEnumAsInt;

NAN_METHOD(initializeClrFunc)
{
    return ClrFunc::Initialize(args);
}

#pragma unmanaged
void init(Handle<Object> target) 
{
    debugMode = (0 < GetEnvironmentVariable("EDGE_DEBUG", NULL, 0));
    DBG("edge::init");
    V8SynchronizationContext::Initialize();
    enableScriptIgnoreAttribute = (0 < GetEnvironmentVariable("EDGE_ENABLE_SCRIPTIGNOREATTRIBUTE", NULL, 0));
    enableMarshalEnumAsInt = (0 < GetEnvironmentVariable("EDGE_MARSHAL_ENUM_AS_INT", NULL, 0));
    NODE_SET_METHOD(target, "initializeClrFunc", initializeClrFunc);
}

#pragma unmanaged
NODE_MODULE(edge, init);
