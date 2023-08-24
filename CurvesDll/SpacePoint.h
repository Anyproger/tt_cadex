#pragma once
#ifdef CURVESDLL_EXPORTS
#define CURVESDLL_API __declspec(dllexport)
#else
#define CURVESDLL_API __declspec(dllimport)
#endif


#include "pch.h"


class CURVESDLL_API SpacePoint
{
public:
	using ComponentType = double;

	ComponentType x = 0;
	ComponentType y = 0;
	ComponentType z = 0;
	
	friend CURVESDLL_API std::ostream& operator<< (std::ostream& out, const SpacePoint& point);
};
