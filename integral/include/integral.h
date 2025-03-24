#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <etl/array.h>

/*  DESCRIPTION:
      This header file declares the Integral class, which provides a method to numerically integrate a polynomial function.
      It defines a method using the trapezoidal rule to approximate the definite integral of a given polynomial.

    MAINTENANCE:
      The coefficients of the polynomial are stored in an ETL array.
      Future improvements could include additional integration methods.
      NUM_SAMPLES is adjustable in the constructor. Higher number might improve accuracy.
      This implementation uses MAX_POLY_DEGREE to define coefficient array size.
*/

#define MAX_POLY_DEGREE 11

class Integral {
private:
    size_t num_samples;
    //size_t max_poly_degree;

    float evaluatePolynomial(const etl::array<float, MAX_POLY_DEGREE>& coeffs, float x) const;

public:
    Integral(size_t num_samples);
    float integratePolynomial(const etl::array<float, MAX_POLY_DEGREE>& coeffs, const float lowerLimit, const float upperLimit) const;
};

#endif // INTEGRAL_H