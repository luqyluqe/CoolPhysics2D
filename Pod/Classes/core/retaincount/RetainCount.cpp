#include "RetainCount.h"

BEGIN_NAMESPACE_COOLPHYSICS2D
BEGIN_NAMESPACE_RETAINCOUNT

RetainCount::RetainCount():_count(new int(1)){}
RetainCount::RetainCount(RetainCount const& retainCount):_count(retainCount._count)
{
    ++*_count;
}
RetainCount::~RetainCount()
{
    if(--*_count==0) delete _count;
}
bool RetainCount::only()const{return *_count==1;}

END_NAMESPACE_RETAINCOUNT
END_NAMESPACE_COOLPHYSICS2D
