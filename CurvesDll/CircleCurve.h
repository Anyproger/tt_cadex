#pragma once
#ifdef CURVESDLL_EXPORTS
#define CURVESDLL_API __declspec(dllexport)
#else
#define CURVESDLL_API __declspec(dllimport)
#endif


#include "ICurve.h"


class SpacePoint;

class CURVESDLL_API CircleCurve :
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

