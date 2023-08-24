#pragma once


class SpacePoint
{
public:
	using ComponentType = double;

	ComponentType x = 0;
	ComponentType y = 0;
	ComponentType z = 0;
	
	friend __declspec(dllimport) std::ostream& operator<< (std::ostream& out, const SpacePoint& point);
};
