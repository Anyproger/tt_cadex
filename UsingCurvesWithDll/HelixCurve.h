#pragma once
#include "stdafx.h"
#include "ICurve.h"


class HelixCurve :
    public ICurve
{
public:
	HelixCurve();
	HelixCurve(const ParameterType& radius, const ParameterType& verticalStep);
	virtual ~HelixCurve();

	void setRadius(const ParameterType& t);
	void setVerticalStep(const ParameterType& t);
	SpacePoint getPoint(const ParameterType& t) override;
	SpacePoint getFirstDerivativePoint(const ParameterType& t) override;

private:
	ParameterType r = 1;
	ParameterType s = 1;
};

