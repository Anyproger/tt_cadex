#include "stdafx.h"
#include "CircleGenerator.h"
#include "CircleCurve.h"


CircleGenerator::CircleGenerator()
{
}

CircleGenerator::~CircleGenerator()
{
}

ICurve* CircleGenerator::generate()
{
	constexpr unsigned int MAX_RADIUS = 100;
	const unsigned int radius = rand() % MAX_RADIUS + 1;
	return new CircleCurve(radius);
}