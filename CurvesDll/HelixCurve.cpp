#include "pch.h"
#include "HelixCurve.h"
#include "SpacePoint.h"


HelixCurve::HelixCurve() :
	r(1),
	s(1)
{
}

HelixCurve::HelixCurve(const ParameterType& radius, const ParameterType& verticalStep) :
	r(radius),
	s(verticalStep)
{
};

HelixCurve::~HelixCurve()
{
}

void HelixCurve::setRadius(const ParameterType& t)
{
	this->r = std::abs(t);
}

void HelixCurve::setVerticalStep(const ParameterType& t)
{
	this->s = std::abs(t);
}

SpacePoint HelixCurve::getPoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = static_cast<SpacePoint::ComponentType>(r) * cos(t);
	result.y = static_cast<SpacePoint::ComponentType>(r) * sin(t);
	result.z = static_cast<SpacePoint::ComponentType>(s) * t;

	return result;
}

SpacePoint HelixCurve::getFirstDerivativePoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = -static_cast<SpacePoint::ComponentType>(r) * sin(t);
	result.y = static_cast<SpacePoint::ComponentType>(r) * cos(t);
	result.z = static_cast<SpacePoint::ComponentType>(s);

	return result;
}