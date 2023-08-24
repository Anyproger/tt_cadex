#include "pch.h"
#include "SpacePoint.h"


CURVESDLL_API std::ostream& operator<< (std::ostream& out, const SpacePoint& point)
{
	out << "(" << point.x << ", " << point.y << ", " << point.z << ")";
	return out;
}
