#pragma once
#include "stdafx.h"


class ICurve;

class ICurveGenerator
{
public:
	ICurveGenerator() {};
	~ICurveGenerator() {};

	virtual ICurve* generate() = 0;
};

