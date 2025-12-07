#include "FFT.h"
#include <cmath>


COMPLEX FFT::OmegaToPower(int num_of_points, int exponent)
{
	double ang = (-2 * M_PI * ((double)exponent)) / ((double) num_of_points);
	double rl = std::cos(ang);
	double img = std::sin(ang);
	return COMPLEX (rl, img);
}

void FFT::CreateFourierMatrix(int dimension_size)
{
	std::vector<std::thread> thrds;
	const unsigned int num_of_threads = std::thread::hardware_concurrency();
	ClearMatrix(fourier_mtx);
	fourier_mtx = CreateMatrix<COMPLEX>(dimension_size, dimension_size);

	if (dimension_size > 0)
	{
		for (int i = 0; i < num_of_threads; i++)
		{
			thrds.emplace_back([i, this, num_of_threads, dimension_size]() {
				int row = 0;
				int col = i;
				double dim_size = dimension_size;
				
				while (row < dimension_size)
				{
					if (col >= dimension_size)
					{
						int r_incrementor = col / dimension_size;
						row += r_incrementor;
						col = col % dimension_size;
					}

					if (row < dimension_size && col < dimension_size)
					{
						fourier_mtx[row][col] = this->OmegaToPower(dimension_size, (row * col) );
						fourier_mtx[row][col].MultiplyByScalar(1 / std::sqrt(dim_size));
					}

					col += num_of_threads;
				}
			});
		}

		for (auto& th : thrds)
			th.join();
	}
}

void FFT::CalculateFFT(const std::vector<double>& data_set)
{
	MATRIX<COMPLEX> tmp_data;
	for (auto& elm : data_set)
	{
		tmp_data.push_back({ COMPLEX(elm, 0) });
	}
	CalculateFFT(tmp_data);
	ClearMatrix(tmp_data);
}

void FFT::CalculateFFT(const MATRIX<COMPLEX>& data_set)
{
	ClearMatrix(fourier_mtx);
	ClearMatrix(fourier_coeffs);
	ClearMatrix(data);

	data = data_set;
	CreateFourierMatrix(RowSize(data));
	fourier_coeffs = Multiply(fourier_mtx, data);
}

void FFT::FilterCoefficients(double threshold)
{
	std::vector<std::thread> thrds;
	const unsigned int num_of_threads = std::thread::hardware_concurrency();

	for (int i = 0; i < num_of_threads; i++)
	{
		thrds.emplace_back([i, this, num_of_threads, threshold](){
			int index = i;
			while (index < fourier_coeffs.size())
			{
				double abs_val = fourier_coeffs[index][0].getReal();
				if (abs_val < 0)
				{
					abs_val *= -1;
				}
				if (abs_val < threshold)
				{
					fourier_coeffs[index][0].SetReal(0);
				}
				
				abs_val = fourier_coeffs[index][0].getImaginary();
				if (abs_val < 0)
				{
					abs_val *= -1;
				}
				if (abs_val < threshold)
				{
					fourier_coeffs[index][0].SetImaginary(0);
				}
				index += num_of_threads;
			}
		});
	}
	
	for (auto& th : thrds)
		th.join();
}

std::vector<double> FFT::GraphFourierSeries(const int num_of_points, const double delta_size, const double a, const double b)
{
	if (num_of_points <= 0 || b - a <= 0 || delta_size <= 0)
		return {};

	std::vector<std::thread> thrds;
	const unsigned int num_of_threads = std::thread::hardware_concurrency();
	std::vector<double> result(num_of_points);

	for (int i = 0; i < num_of_threads; i++)
	{
		thrds.emplace_back([i, a, b, delta_size, this, num_of_threads, &result](){
			int index = i;

			while (index < result.size())
			{
				result[index] = GraphPointOnFourierSeries(index * delta_size, a, b);
				index += num_of_threads;
			}
		});
	}

	for (auto& th : thrds)
		th.join();

	return result;
}

double FFT::GraphPointOnFourierSeries(const double x, const double a, const double b)
{
	double sum = 0;
	const int rowSize = RowSize(fourier_coeffs);

	for (int k = 0; k < rowSize; k++)
	{
		double ang = (2 * M_PI * k * (x - a)) / (b - a);
		double cos_term = fourier_coeffs[k][0].getReal() * cos(ang);
		double sin_term = fourier_coeffs[k][0].getImaginary() * sin(ang);
		sum += cos_term - sin_term;
	}

	if (rowSize > 0)
		sum /= std::sqrt((double)rowSize);

	return sum;
}

void FFT::DisplayCoefficients()
{
	Display(fourier_coeffs);
}

void FFT::DisplayFourierMatrix()
{
	Display(fourier_mtx);
}

void FFT::DisplayData()
{
	Display(data);
}

