#pragma once
#ifdef CURVESDLL_EXPORTS
#define CURVESDLL_API __declspec(dllexport)
#else
#define CURVESDLL_API __declspec(dllimport)
#endif


#include "ICurve.h"


class CURVESDLL_API HelixCurve :
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

