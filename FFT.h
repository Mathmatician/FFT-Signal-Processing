#include <vector>
#include "Complex.h"
#include "Matrix.h"

class FFT {
	private:
		MATRIX<COMPLEX> fourier_coeffs;
		MATRIX<COMPLEX> fourier_mtx;
		MATRIX<COMPLEX> data;

	public:
		COMPLEX OmegaToPower(int num_of_points, int exponent);
		void CreateFourierMatrix(int dimension_size);
		void CalculateFFT(const std::vector<double>& data_set);
		void FilterCoefficients(double threshold);
		void CalculateFFT(const MATRIX<COMPLEX>& data_set);
		std::vector<double> GraphFourierSeries(const int num_of_points, const double delta_size, const double a, const double b);
		double GraphPointOnFourierSeries(const double x, const double a, const double b);
		void DisplayCoefficients();
		void DisplayFourierMatrix();
		void DisplayData();
};

