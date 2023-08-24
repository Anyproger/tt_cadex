#pragma once
#ifdef CURVESDLL_EXPORTS
#define CURVESDLL_API __declspec(dllexport)
#else
#define CURVESDLL_API __declspec(dllimport)
#endif


#include "ICurve.h"


class SpacePoint;

class CURVESDLL_API EllipseCurve :
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

