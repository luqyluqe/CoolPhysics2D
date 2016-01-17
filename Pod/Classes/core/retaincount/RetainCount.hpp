#ifndef COOLPHYSICS2D_HANDLE_RETAINCOUNT_HPP
#define COOLPHYSICS2D_HANDLE_RETAINCOUNT_HPP

#include "config.h"
#include "retaincount_config.h"

BEGIN_NAMESPACE_COOLPHYSICS2D
BEGIN_NAMESPACE_RETAINCOUNT

class RetainCount
{
public:
    RetainCount();
    RetainCount(RetainCount const& retainCount);
//    RetainCount& operator=(RetainCount const& retainCount);
    ~RetainCount();
    bool only()const;
private:
    int* _count;
};

END_NAMESPACE_RETAINCOUNT
END_NAMESPACE_COOLPHYSICS2D

#endif
