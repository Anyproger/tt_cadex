#include "pch.h"
#include "CircleCurve.h"
#include "SpacePoint.h"


CircleCurve::CircleCurve() : t{1}
{
}

CircleCurve::CircleCurve(const ParameterType& t) : t(t) 
{
};

CircleCurve::~CircleCurve()
{
}

void CircleCurve::setRadius(const ParameterType& t)
{
	this->t = std::abs(t);
}

ICurve::ParameterType CircleCurve::getRadius()
{
	return this->t;
}

SpacePoint CircleCurve::getPoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = static_cast<SpacePoint::ComponentType>(t) * cos(t);
	result.y = static_cast<SpacePoint::ComponentType>(t) * sin(t);
	result.z = 0;

	return result;
}

SpacePoint CircleCurve::getFirstDerivativePoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = -static_cast<SpacePoint::ComponentType>(t) * sin(t);
	result.y = static_cast<SpacePoint::ComponentType>(t) * cos(t);
	result.z = 0;

	return result;
}
