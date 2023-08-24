#include "Tasks.h"

Tasks::Tasks()
{

}

Tasks::~Tasks()
{

}

Tasks& Tasks::getInstance()
{
	static Tasks instance;
	return instance;
}

#include "CurveGenerator.h"
#include "CircleCurve.h"
#include "ICurve.h"
#include "SpacePoint.h"
void Tasks::start()
{
	using namespace std;
	vector<ICurve*> curves = CurveGenerator::getInstance().generate(10);
	cout << "2. Generated " << curves.size() << " curves" << endl;

	constexpr double t = 3.1415 / 4.0;
	cout << "3. Curve solutions by t = PI/4" << endl <<
		fixed << showpoint << setprecision(3);
	cout << "\tcurve point | curve derivative point" << endl;
	{
		for (auto&& curve : curves)
		{
			if (!curve)
			{
				cout << "\tnullptr to curve obj" << endl;
				continue;
			}
			cout << "\t" << curve->getPoint(t) << " | " << curve->getFirstDerivativePoint(t) << endl;
		}
	}

	cout << "4. Select circles from generated:";
	vector<CircleCurve*> circles(curves.size());
	{
		int total = 0;
		for (auto&& curve : curves)
		{
			void* ptr = dynamic_cast<CircleCurve*>(curve);
			if (!ptr)
			{
				continue;
			}

			circles[total] = (CircleCurve*)ptr;
			total++;
		}
		cout << "\tselected " << (total) << " circles" << endl;
	}

	cout << "5. Sorted the circles by it radius:" << endl <<
		fixed << showpoint << setprecision(3);
	{
		sort(begin(circles), end(circles),
			[](CircleCurve* l, CircleCurve* r) {
				return l && r && l->getRadius() < r->getRadius();
			}
		);

		int idx = 0;
		for (auto&& circle : circles)
		{
			if (!circle) continue;

			cout << "\t#" << idx << ": circle with R = " << circle->getRadius() << endl;
			idx++;
		}
	}

	cout << "6. Total sum of circles radius:" << endl;
	{
		ICurve::ParameterType sum = 0; 
		auto begin = std::chrono::steady_clock::now();
		for (auto&& circle : circles)
		{
			if (!circle) continue;
			sum += circle->getRadius();
		}
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		cout << "\tvalue = " << setprecision(3) << sum << endl <<
			"\tby " << setprecision(9) << time << endl;
	}

	cout << "8. Total sum of circles radius (OpenMP):" << endl;
	{
		ICurve::ParameterType sum = 0;
		auto begin = std::chrono::steady_clock::now();
		#pragma omp parallel for num_threads(10)
		for (auto&& circle : circles)
		{
			if (!circle) continue;
			sum += circle->getRadius();
		}
		auto end = std::chrono::steady_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		cout << "\tvalue = " << setprecision(3) << sum << endl <<
			"\tby " << setprecision(9) << time << endl;
	}

	// memory release
	{
		for (auto&& curve : curves)
		{
			delete curve;
			curve = nullptr;
		}
	}
}