//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
real_T b_norm(const ::coder::array<real_T, 2U> &x)
{
  real_T y;
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    y = 0.0;
  } else if ((x.size(0) == 1) || (x.size(1) == 1)) {
    int32_T i;
    y = 0.0;
    i = x.size(0) * x.size(1);
    for (int32_T j{0}; j < i; j++) {
      y += muDoubleScalarAbs(x[j]);
    }
  } else {
    int32_T j;
    boolean_T exitg1;
    y = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j <= x.size(1) - 1)) {
      real_T s;
      int32_T i;
      s = 0.0;
      i = x.size(0);
      for (int32_T b_i{0}; b_i < i; b_i++) {
        s += muDoubleScalarAbs(x[b_i + x.size(0) * j]);
      }
      if (muDoubleScalarIsNaN(s)) {
        y = rtNaN;
        exitg1 = true;
      } else {
        if (s > y) {
          y = s;
        }
        j++;
      }
    }
  }
  return y;
}

} // namespace coder

// End of code generation (norm.cpp)
