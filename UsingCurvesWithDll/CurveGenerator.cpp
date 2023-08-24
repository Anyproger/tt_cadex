#include "stdafx.h"
#include "CurveGenerator.h"
#include "ICurve.h"

#include "CircleGenerator.h"
#include "EllipseGenerator.h"
#include "HelixGenerator.h"
#include "ICurveGenerator.h"



CurveGenerator::CurveGenerator() :
	generators{
		new CircleGenerator(), 
		new EllipseGenerator(), 
		new HelixGenerator()
	}
{
	generator = generators[0];
}

CurveGenerator::~CurveGenerator()
{
	for (auto&& generator : generators)
	{
		delete generator;
		generator = nullptr;
	}
}

CurveGenerator& CurveGenerator::getInstance()
{
	static CurveGenerator instance;
	return instance;
}

void CurveGenerator::switchGenerator()
{
	generator = generators[rand() % generators.size()];
}

ICurve* CurveGenerator::createCurve()
{
	return generator->generate();
}

std::vector<ICurve*> CurveGenerator::generate(const size_t count)
{
	std::vector<ICurve*> result(count);

	int created = 0;
	while (created < count)
	{
		switchGenerator();
		result[created] = createCurve();

		created++;
	}

	return result;
}
