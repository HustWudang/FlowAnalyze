// libs && header files included.
#include "flow.h"

// namespace.
using namespace std;

// main function.
int main()
{
	int CASE = 2;
	if (1 == CASE)
	{
		// porous flow problems.
		CFlowPorous mFlowPorous;
		mFlowPorous.Initialize(1.0, 100000, 0, 1e-12, 0.001, 2e10);
		mFlowPorous.FileOut_PressureField_AtCertainTime("poro_pressure_field_t.txt", 0.001, 10, 10);
	}
	else if (2 == CASE)
	{
		// porous flow problems.
		CFlowFracture mFlowFracture;
		mFlowFracture.Initialize(1.0, 1000000, 2e9, 0.001, 3e-5);
		mFlowFracture.FileOut_PressureField_AtCertainTime("frac_pressure_field_t.txt", 0.003, 10, 10);
	}
	else if (3 == CASE)
	{

	}
	else { cout << "[Error] wrong case !\n"; }


	system("pause");
	return 0;
}