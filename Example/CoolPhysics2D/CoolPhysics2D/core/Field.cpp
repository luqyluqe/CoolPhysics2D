#include "Field.h"

BEGIN_NAMESPACE_COOLPHYSICS2D

Field::Field(const Rectangle& range):_range(range)
{
    enable();
}

Field::~Field(){}

void Field::enable()
{
    _enabled=true;
}
void Field::disable()
{
    _enabled=false;
}
bool Field::enabled()const
{
    return _enabled;
}

END_NAMESPACE_COOLPHYSICS2D