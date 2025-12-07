# FFT Signal Processing

## Overview

This project provides a lightweight C++ implementation of the **Fast Fourier Transform (FFT)** along with Fourier-based signal reconstruction tools. It allows users to:

- Compute Fourier coefficients from real-valued input data
- Filter frequency components by thresholding
- Reconstruct a signal using a Fourier Series
- Generate interpolated output samples for graphing or analysis

The implementation is fully self-contained, written from scratch, and designed for learning, experimentation, and portfolio demonstration.

---

## Features

- Fast Fourier Transform (FFT) implementation  
- Fourier coefficient filtering for noise reduction  
- Fourier-series interpolation and reconstruction  
- Clean, easy-to-use C++ API  
- Works with `std::vector<double>` input data  
- Produces smooth interpolated output for graphing  

---

## Example Usage (from `main.cpp`)

### Step 1: Load Input Data
```cpp
std::vector<double> data;
LoadData(data);
```

### Step 2: Create the FFT Object
```cpp
FFT fft;
```

### Step 3: Compute Fourier Coefficients
```cpp
fft.CalculateFFT(data);
```

### Step 4: Optional – Filter Coefficients
```cpp
fft.FilterCoefficients(0);  // 0 = no filtering
```
Higher values remove more frequency components.

### Step 5: Generate Interpolated Fourier-Series Output
```cpp
int num_of_points = data.size();
double delta = 0.5;
double start_point = 0;
double end_point = data.size();

std::vector<double> interpolated_data =
    fft.GraphFourierSeries(num_of_points, delta, start_point, end_point);
```

### Parameter Descriptions
```
num_of_points  - Number of reconstructed sample points to generate
delta          - Spacing between the generated x-values
start_point    - First x-value of the interpolation interval
end_point      - Last x-value of the interpolation interval
return value   - Vector of interpolated y-values
```

### Step 6: Display or Graph the Output
```cpp
double x = 0;
for (auto& elm : interpolated_data)
{
    std::cout << "x = " << x << ", y = " << elm << std::endl;
    x += delta;
}
```

---

## Building the Project

This project includes a Makefile for compiling all source files and creating the final executable.

To build the program, simply run:

```bash
make
```

This will:

- Compile `main.cpp`, `Complex.cpp`, and `FFT.cpp`
- Produce object files: `main.o`, `Complex.o`, `FFT.o`
- Link them into an executable named **program**

### Makefile
```make
all: main.o Complex.o FFT.o
        g++ -g main.o Complex.o FFT.o -o program

main.o: main.cpp
        g++ -g -c main.cpp

Complex.o: Complex.cpp
        g++ -g -c Complex.cpp

FFT.o: FFT.cpp
        g++ -g -c FFT.cpp

clean:
        rm -f *.o program
```

Clean the build with:

```bash
make clean
```

Run the executable with:

```bash
./program
```

---

## File Structure

```
FFT-Signal-Processing/
    README.md
    FFT.h
    FFT.cpp
    Complex.cpp
    main.cpp
```

---

## Intended Use

This project is useful for:

- Learning FFT and Fourier Series reconstruction  
- Demonstrating mathematical and algorithmic skills  
- Filtering or smoothing discrete signals  
- Experimenting with frequency-domain manipulation  

It is dependency-free and easy to integrate into other applications.

---

## License

This project is released under the MIT License, allowing free use, modification, and distribution.

```
Copyright (c) 2025 Jerome Richards
```

---

## Author

Created by **Jerome Richards**  
**LinkedIn:** https://www.linkedin.com/in/jerome-richards343  
**GitHub:** https://github.com/Mathmatician
