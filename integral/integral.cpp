#include "integral.h"
#include <cmath>


/*  DESCRIPTION:
      This file implements the Integral class functions for numerical integration.
      The `evaluatePolynomial` method computes the polynomial's value at a given x using its coefficients.
      The `integratePolynomial` method applies the trapezoidal rule to approximate the integral.
    MAINTENANCE:
      Additional error handling could be added for edge cases, such as when lowerLimit == upperLimit.
      Making NUM_SAMPLES dynamically configurable could allow for improved precision control.
*/

Integral::Integral(size_t num_samples) : num_samples(num_samples) {
    if (num_samples <= 0) {
        throw std::invalid_argument("num_samples must be greater than 0");
    }
}

float Integral::evaluatePolynomial(const etl::array<float, MAX_POLY_DEGREE>& coeffs, float x) const {
    float result = 0.0f;
    float power = 1.0f;
    
    for (size_t i = 0; i < coeffs.size() + 1; ++i) {
        result += coeffs[i] * power;
        power *= x;
    }

    return result;
}

float Integral::integratePolynomial(const etl::array<float, MAX_POLY_DEGREE>& coeffs, const float lowerLimit, const float upperLimit) const {
    // No area under the curve when the limits are the same
    if (fabs(lowerLimit - upperLimit) < 1e-6) {
        return 0.0f; 
    }

    
    float step = (upperLimit - lowerLimit) / num_samples;
    float integral = 0.0f;

    for (size_t i = 0; i < num_samples; ++i) {
        float x0 = lowerLimit + i * step;
        float x1 = x0 + step;
        float y0 = evaluatePolynomial(coeffs, x0);
        float y1 = evaluatePolynomial(coeffs, x1);
        integral += (y0 + y1) * 0.5f * step;
    }

    return integral;
}