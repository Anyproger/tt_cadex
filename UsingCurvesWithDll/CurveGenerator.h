#pragma once
#include "stdafx.h"


class ICurve;
class ICurveGenerator;

class CurveGenerator
{
private:
	CurveGenerator();
	CurveGenerator(CurveGenerator&&) = delete;
	~CurveGenerator();

	CurveGenerator& operator=(const CurveGenerator&) = delete;

public:
	static CurveGenerator& getInstance();

	std::vector<ICurve*> generate(const size_t count);

private:
	ICurve* createCurve();
	void switchGenerator();

	std::vector<ICurveGenerator*> generators;
	ICurveGenerator* generator = nullptr;
};

