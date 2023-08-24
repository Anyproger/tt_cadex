#include "EllipseGenerator.h"
#include "EllipseCurve.h"


EllipseGenerator::EllipseGenerator()
{
}

EllipseGenerator::~EllipseGenerator()
{
}

ICurve* EllipseGenerator::generate()
{
	constexpr unsigned int MAX_AXIS = 100;
	unsigned int radius1 = 0;
	unsigned int radius2 = 0;
	do
	{
		radius1 = rand() % MAX_AXIS + 1;
		radius2 = rand() % MAX_AXIS + 1;		
	} 
	while (radius1 == radius2);
	return new EllipseCurve(radius1, radius2);
}