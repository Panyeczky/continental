#include <etl/array.h>
#include "integral.h"
#include <cstdio>

int main() {
    // parameters for integral
    size_t num_samples = 1000;
    Integral integral(num_samples);
    
    // parameters for integratePolynomial
    etl::array<float, 11> coeffs = {1.0f, -2.0f, 3.0f, 0.0f, 5.0f};
    float lower = 0.0f, upper = 10.0f;
    
    printf("Integral is: %f\n", integral.integratePolynomial(coeffs, lower, upper));
  
    return 0;
}
