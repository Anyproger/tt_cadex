#include "HelixGenerator.h"
#include "HelixCurve.h"


HelixGenerator::HelixGenerator()
{
}

HelixGenerator::~HelixGenerator()
{
}

ICurve* HelixGenerator::generate()
{
	constexpr unsigned int MAX_RADIUS = 100;
	constexpr unsigned int MAX_VSTEP = 25;
	const unsigned int radius = rand() % MAX_RADIUS + 1;
	const unsigned int verticalStep = rand() % MAX_VSTEP + 1;
	return new HelixCurve(radius, verticalStep);
}