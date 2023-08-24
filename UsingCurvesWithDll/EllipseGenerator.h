#pragma once
#include "stdafx.h"
#include "ICurveGenerator.h"


class EllipseGenerator :
    public ICurveGenerator
{
public:
    EllipseGenerator();
    virtual ~EllipseGenerator();
    
    ICurve* generate() override;
};

