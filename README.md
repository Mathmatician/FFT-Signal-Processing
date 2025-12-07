Overview

This project provides a lightweight C++ implementation of the Fast Fourier Transform (FFT) and Fourier-based signal reconstruction tools.
It allows users to:

Compute Fourier coefficients from real-valued input data

Filter frequency components by thresholding

Reconstruct a signal using a Fourier Series

Generate interpolated output samples for graphing or analysis

The implementation is fully self-contained, written from scratch, and designed for learning, experimentation, and portfolio demonstration.

Features

✔ Fast Fourier Transform (FFT) implementation

✔ Fourier coefficient filtering for noise reduction

✔ Fourier-series interpolation and reconstruction

✔ Clean, easy-to-use C++ API

✔ Works with simple std::vector<double> input

✔ Outputs smooth interpolated values suitable for plotting

Example Usage (from main.cpp)

Below is the recommended usage flow.

Step 1 — Load Input Data

Load your signal values into a standard vector:

std::vector<double> data;
LoadData(data);


This can represent any sequence of samples such as audio, sensor data, or manually entered values.

Step 2 — Create the FFT Object
FFT fft;

Step 3 — Compute Fourier Coefficients
fft.CalculateFFT(data);


This generates the frequency-domain representation of the signal.

Step 4 — (Optional) Filter Coefficients

Remove unwanted frequencies by applying a threshold:

fft.FilterCoefficients(0);


0 → no filtering

Higher values → removes small-magnitude frequency components

Useful for smoothing or denoising.

Step 5 — Generate Interpolated Fourier-Series Output
int num_of_points = data.size();
double delta = 0.5;
double start_point = 0;
double end_point = data.size();

std::vector<double> interpolated_data =
    fft.GraphFourierSeries(num_of_points, delta, start_point, end_point);

Parameter Explanation
Parameter	Meaning
num_of_points	Number of reconstructed sample points to generate
delta	Distance between x-values (spacing)
start_point	First x-value of interpolation domain
end_point	Last x-value of interpolation domain
Return Value	A vector of y-values representing the interpolated Fourier series

This allows users to create smooth graphs or custom sampling grids.

Step 6 — Display or Graph the Results
std::cout << "Input           Output\n";
std::cout << "----------------------------\n";

double x = 0;
for (auto& elm : interpolated_data)
{
    std::cout << std::fixed << std::setprecision(4)
              << "x = " << x << ",     y = " << elm << std::endl;
    x += delta;
}


You may pass these values into a UI framework or a plotting library such as matplotlib, gnuplot, Excel, or ImGui.

Building the Project

Compile using any C++17-capable compiler:

g++ -std=c++17 main.cpp FFT.cpp -o fft_demo


Run with:

./fft_demo

File Structure
/FFT-Signal-Processing
    README.txt
    FFT.h
    FFT.cpp
    main.cpp

Intended Use

This project is ideal for:

Learning how FFT and Fourier Series reconstruction work

Demonstrating algorithmic and mathematical skill to employers

Filtering and smoothing signals

Experimenting with frequency-domain manipulation

It is lightweight, dependency-free, and easy to integrate into other projects.

License

This project is released under the MIT License, allowing free use and modification.

Copyright (c) 2025 Jerome Richards Jr.

Contact / Author

Created by Jerome Richards
For questions or feedback, feel free to reach out via GitHub or LinkedIn.

https://www.linkedin.com/in/jerome-richards343/
