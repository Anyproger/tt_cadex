#pragma once
#include "stdafx.h"
#include "ICurveGenerator.h"


class CircleGenerator :
    public ICurveGenerator
{
public:
    CircleGenerator();
    virtual ~CircleGenerator();

    ICurve* generate() override;
};

