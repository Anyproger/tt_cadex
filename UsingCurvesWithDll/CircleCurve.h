#pragma once
#include "stdafx.h"
#include "ICurve.h"


class SpacePoint;

class CircleCurve :
    public ICurve
{
public:
	CircleCurve();
	CircleCurve(const ParameterType& t);
	virtual ~CircleCurve();

	void setRadius(const ParameterType& t);
	ParameterType getRadius();

	SpacePoint getPoint(const ParameterType& t) override;
	SpacePoint getFirstDerivativePoint(const ParameterType& t) override;

private:
	ParameterType t = 1;
};

