// pragma once.
#pragma once

// libs included.
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

// namespace.
using namespace std;

// define.
# define PI 3.14159265358979323846

// flow classes.

// matrix flow class.
class CFlowPorous
{
public:
	double Length;
	double Pressure_Left;
	double Pressure_Right;
	double Permeability;
	double Viscosity;
	double BiotModulus;
	// initialize.
	void Initialize(double l, double p_l, double p_r, double perm, double visco, double BiMo);
	// output pressure at x at t.
	double GetAnalyticalPressure(double x, double t, int order);
	// write pressure distribution at t.
	void FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section, int i_order);
};

// fracture flow class.
class CFlowFracture
{
public:
	double Length;
	double Pressure_Left;
	//double Pressure_Right;
	double BulkModulus;
	double Viscosity;
	double FracAperture;
	// initialize.
	void Initialize(double l, double p_l, double bulk, double visco, double aperture);
	// output pressure at x at t.
	double GetAnalyticalPressure(double x, double t, int order);
	// write pressure distribution at t.
	void FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section, int i_order);
};

// Consolidation class
class CConsolidation
{
public:
	double Height;
	double Pressure_Top;
	double Permeability;
	double Viscosity;
	double BiotModulus;
	double BulkModulus;
	// initialize.
	void Initialize(double l, double p_l, double bulk, double visco, double aperture);
	// output pressure at z at t.
	double GetAnalyticalPressure(double x, double t, int order);
	// output displacement at z at t.
	double GetAnalyticalDispl(double x, double t, int order);
	// write pressure distribution at t.
	void FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section);
	// write displacement distribution at t.
	void FileOut_DisplField_AtCertainTime(std::string filename, double t, int i_section);
};