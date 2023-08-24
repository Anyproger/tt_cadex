#pragma once
#ifdef CURVESDLL_EXPORTS
#define CURVESDLL_API __declspec(dllexport)
#else
#define CURVESDLL_API __declspec(dllimport)
#endif


class CURVESDLL_API SpacePoint;

class CURVESDLL_API ICurve
{
public:
	ICurve() {};
	virtual ~ICurve() {};

	using ParameterType = double;

	virtual SpacePoint getPoint(const ParameterType& t) = 0;
	virtual SpacePoint getFirstDerivativePoint(const ParameterType& t) = 0;
};

