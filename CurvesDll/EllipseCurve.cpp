#include "pch.h"
#include "EllipseCurve.h"
#include "SpacePoint.h"


EllipseCurve::EllipseCurve() :
	xHalfAxis(1), 
	yHalfAxis(1)
{
}

EllipseCurve::EllipseCurve(const ParameterType& xHalfAxis, const ParameterType& yHalfAxis) : 
	xHalfAxis(xHalfAxis), 
	yHalfAxis(yHalfAxis)
{
};

EllipseCurve::~EllipseCurve()
{
}

void EllipseCurve::setXHalfAxis(const ParameterType& t)
{
	this->xHalfAxis = std::abs(t);
}

void EllipseCurve::setYHalfAxis(const ParameterType& t)
{
	this->yHalfAxis = std::abs(t);
}

SpacePoint EllipseCurve::getPoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = static_cast<SpacePoint::ComponentType>(xHalfAxis) * cos(t);
	result.y = static_cast<SpacePoint::ComponentType>(yHalfAxis) * sin(t);
	result.z = 0;

	return result;
}

SpacePoint EllipseCurve::getFirstDerivativePoint(const ParameterType& t)
{
	SpacePoint result;
	result.x = -static_cast<SpacePoint::ComponentType>(xHalfAxis) * sin(t);
	result.y = static_cast<SpacePoint::ComponentType>(yHalfAxis) * cos(t);
	result.z = 0;

	return result;
}