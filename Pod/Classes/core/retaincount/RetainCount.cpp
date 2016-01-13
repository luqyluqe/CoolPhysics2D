#include "RetainCount.hpp"

BEGIN_NAMESPACE_COOLPHYSICS2D
BEGIN_NAMESPACE_RETAINCOUNT

RetainCount::RetainCount():count(new int(1)){}
RetainCount::RetainCount(RetainCount const& retainCount):count(retainCount.count){++*count;}
RetainCount::~RetainCount()
{
    if(--*count==0) delete count;
}
bool RetainCount::only()const{return *count==1;}

END_NAMESPACE_RETAINCOUNT
END_NAMESPACE_COOLPHYSICS2D
