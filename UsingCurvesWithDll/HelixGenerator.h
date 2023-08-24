#pragma once
#include "stdafx.h"
#include "ICurveGenerator.h"


class HelixGenerator :
    public ICurveGenerator
{
public:
    HelixGenerator();
    ~HelixGenerator();

    ICurve* generate() override;
};

