#pragma once
#include "stdafx.h"


class SpacePoint;

class ICurve
{
public:
	ICurve() {};
	virtual ~ICurve() {};

	using ParameterType = double;

	virtual SpacePoint getPoint(const ParameterType& t) = 0;
	virtual SpacePoint getFirstDerivativePoint(const ParameterType& t) = 0;
};

