// headers included.
#include "flow.h"

// implementation of class functions.

///// class CFlowPorous /////

// initialize.
void CFlowPorous::Initialize(double l, double p_l, double p_r, double perm, double visco, double BiMo)
{
	Length = l;
	Pressure_Left = p_l;
	Pressure_Right = p_r;
	Permeability = perm;
	Viscosity = visco;
	BiotModulus = BiMo;
}

// output pressure at x at t.
double CFlowPorous::GetAnalyticalPressure(double x, double t, int order)
{
	double part_1 = Pressure_Left + x / Length * (Pressure_Right - Pressure_Left);
	double part_2 = 0;
	for (int i_accum = 1; i_accum <= order; i_accum++)
	{
		double coeff = 2.0 / PI;
		double k = Permeability / Viscosity * BiotModulus;
		double temp_1 = exp((-k) * i_accum * i_accum * PI * PI / Length / Length * t);
		double temp_2 = (Pressure_Right*cos(i_accum*PI) - Pressure_Left) / i_accum;
		double temp_3 = sin(i_accum*PI*x / Length);
		double temp_all = coeff * temp_1 * temp_2 *temp_3;
		part_2 += temp_all;
	}
	double Pressure_x_t = part_1 + part_2;
	return Pressure_x_t;
}

// write pressure distribution at t.
void CFlowPorous::FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section, int i_order)
{
	// open file and write.
	ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		// output data.
		fout << t << "\n";
		for (int i_point = 0; i_point <= i_section; i_point++)
		{
			// compute data.
			double x_crd = 0 + Length / i_section * i_point;
			double x_pressure = GetAnalyticalPressure(x_crd, t, i_order);
			fout << x_crd << "\t" << x_pressure << "\n";
		}
		// close file.
		fout.close();
		cout << "[Msg] file wirtten successfully ...\n";
	}
	else
	{
		cout << "[Error-File] cannot open file !\n";
	}

}


// initialize.
void CFlowFracture::Initialize(double l, double p_l, double bulk, double visco, double aperture)
{
	Length = l;
	Pressure_Left = p_l;
	BulkModulus = bulk;
	Viscosity = visco;
	FracAperture = aperture;
}

// output pressure at x at t.
double CFlowFracture::GetAnalyticalPressure(double x, double t, int order)
{
	double part_1 = 1;
	double part_2 = 0;
	for (int i_accum = 0; i_accum <= order; i_accum++)
	{
		double coeff = 4.0 / PI;
		double T = BulkModulus * (FracAperture*FracAperture/12.0/Viscosity/Length/Length)*t;
		double Kesai = (Length - x) / Length;
		double temp_1 = exp(-(2.0*i_accum + 1)*(2.0*i_accum + 1)*(T / 4.0)*PI*PI);
		double temp_2 = cos((2.0*i_accum + 1)*PI / 2.0*Kesai);
		double temp_3 = pow(-1, (i_accum + 1)) / (2 * i_accum + 1);
		double temp_all = coeff * temp_1 * temp_2 *temp_3;
		part_2 += temp_all;
	}
	double Pressure_x_t = (part_1 + part_2)*Pressure_Left;
	return Pressure_x_t;
}

// write pressure distribution at t.
void CFlowFracture::FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section, int i_order)
{
	// open file and write.
	ofstream fout;
	fout.open(filename);
	if (fout.is_open())
	{
		// output data.
		fout << t << "\n";
		for (int i_point = 0; i_point <= i_section; i_point++)
		{
			// compute data.
			double x_crd = 0 + Length / i_section * i_point;
			double x_pressure = GetAnalyticalPressure(x_crd, t, i_order);
			// output data.
			fout << x_crd << "\t" << x_pressure << "\n";
		}
		// close file.
		fout.close();
		cout << "[Msg] file wirtten successfully ...\n";
	}
	else
	{
		cout << "[Error-File] cannot open file !\n";
	}
}

///// CConsolidation /////

// initialize.
void CConsolidation::Initialize(double l, double p_l, double bulk, double visco, double aperture)
{

}

// output pressure at z at t.
double CConsolidation::GetAnalyticalPressure(double x, double t, int order)
{
	return 0;
}

// output displacement at z at t.
double CConsolidation::GetAnalyticalDispl(double x, double t, int order)
{
	return 0;
}

// write pressure distribution at t.
void CConsolidation::FileOut_PressureField_AtCertainTime(std::string filename, double t, int i_section)
{

}

// write displacement distribution at t.
void CConsolidation::FileOut_DisplField_AtCertainTime(std::string filename, double t, int i_section)
{

}