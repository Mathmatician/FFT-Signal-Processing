#include <iostream>

class COMPLEX {
	private:
		double real;
		double imaginary;

	public:
		COMPLEX();
		COMPLEX(double rl, double img);
		COMPLEX(double rl);
		COMPLEX getComplexValue();
		void SetReal(double rl);
		void SetImaginary(double img);
		void MultiplyByScalar(double scl);
		double getReal();
		double getImaginary();
		COMPLEX operator+(const COMPLEX& obj);
		COMPLEX operator-(const COMPLEX& obj);
		COMPLEX operator*(const COMPLEX& obj);
		COMPLEX operator+=(const COMPLEX& obj);
		COMPLEX operator-=(const COMPLEX& obj);
		COMPLEX operator*=(const COMPLEX& obj);
		friend std::ostream& operator<<(std::ostream& os, const COMPLEX& obj);
		void display();
};

