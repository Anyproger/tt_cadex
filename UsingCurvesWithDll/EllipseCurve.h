#pragma once
#include "stdafx.h"
#include "ICurve.h"


class SpacePoint;

class EllipseCurve :
    public ICurve
{
public:
	EllipseCurve();
	EllipseCurve(const ParameterType& xHalfAxis, const ParameterType& yHalfAxis);
	virtual ~EllipseCurve();

	void setXHalfAxis(const ParameterType& t);
	void setYHalfAxis(const ParameterType& t);
	SpacePoint getPoint(const ParameterType& t) override;
	SpacePoint getFirstDerivativePoint(const ParameterType& t) override;

private:
	ParameterType xHalfAxis = 1;
	ParameterType yHalfAxis = 1;
};

