//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mean.h
//
// Code generation for function 'mean'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void mean(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
          ::coder::array<real_T, 2U> &y);

}

// End of code generation (mean.h)
