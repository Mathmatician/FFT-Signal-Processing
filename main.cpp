#include <iostream>
#include <vector>
#include <iomanip>

#include "FFT.h"


void LoadData(std::vector<double>& data);

int main()
{
	// Step 1.) Load the data
	std::vector<double> data;
	LoadData(data);


	// Step 2.) Create your Fast Fourier Transform (FFT) object
	FFT fft;


	// Step 3.) Pass your data (std::vector<double>) into the CalculateFFT to calculate fourier coefficients
	fft.CalculateFFT(data);


	// Step 4.) Optional: Filter out Fourier Coefficients by some given threshold (value of 0 filters no coefficient)
	fft.FilterCoefficients(0);


	// Step 5.) Usage Instructions:---------------------------------------------------------------------------------------
	//                                                                                                                   |
	// Paramters:                                                                                                        |
	// 	num_of_points - number of points to generate                                                                 |
	//                                                                                                                   |
	// 	delta - x distance between points                                                                            |
	//                                                                                                                   |
	// 	start_point - the first x point                                                                              |
	//                                                                                                                   |
	// 	end_point - the last x point                                                                                 |
	//                                                                                                                   |
	// 	interpolated_data - evaluated points of Fourier Series at specified points between start_point and end_point |
	//                                                                                                                   |
	//--------------------------------------------------------------------------------------------------------------------
	int num_of_points = data.size();
	double delta = 0.5;
	double start_point = 0;
	double end_point = data.size();
	std::vector<double> interpolated_data = fft.GraphFourierSeries(num_of_points, delta, start_point, end_point);



	// Step 6.) Display the interpolated data (you can also pass this data to some UI frame work for graphing)
	std::cout << "Input           " << "Output" << std::endl;
	std::cout << "----------------------------" << std::endl;
	double x = 0;
	for (auto& elm : interpolated_data)
	{
		std::cout << std::fixed << std::setprecision(4) << "x = " << x << ",     y = " << elm << std::endl;
		x += delta;
	}


	return 0;
}

void LoadData(std::vector<double>& data)
{
	// Example hard-coded data - put your load data logic here
	data.push_back(-2.2);
	data.push_back(-2.8);
	data.push_back(-6.1);
	data.push_back(-3.9);
	data.push_back(0.0);
	data.push_back(1.1);
	data.push_back(-0.6);
	data.push_back(-1.1);
}
