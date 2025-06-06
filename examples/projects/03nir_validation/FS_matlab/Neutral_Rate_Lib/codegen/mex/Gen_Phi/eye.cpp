//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// eye.cpp
//
// Code generation for function 'eye'
//

// Include files
#include "eye.h"
#include "Gen_Phi_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    wc_emlrtRSI{
        50,    // lineNo
        "eye", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" // pathName
    };

static emlrtRSInfo yc_emlrtRSI{
    21,                           // lineNo
    "checkAndSaturateExpandSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\checkAndSaturateExpandSize.m" // pathName
};

static emlrtRTEInfo
    pc_emlrtRTEI{
        94,    // lineNo
        5,     // colNo
        "eye", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" // pName
    };

// Function Definitions
namespace coder {
void eye(const emlrtStack *sp, real_T varargin_1,
         ::coder::array<real_T, 2U> &b_I)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_t;
  real_T t;
  int32_T loop_ub;
  int32_T m_tmp_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (varargin_1 < 0.0) {
    t = 0.0;
  } else {
    t = varargin_1;
  }
  b_st.site = &yc_emlrtRSI;
  if ((t != muDoubleScalarFloor(t)) || muDoubleScalarIsInf(t) ||
      (t < -2.147483648E+9) || (t > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &o_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (t <= 0.0) {
    b_t = 0.0;
  } else {
    b_t = t;
  }
  if (!(b_t <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  m_tmp_tmp = static_cast<int32_T>(t);
  b_I.set_size(&pc_emlrtRTEI, sp, m_tmp_tmp, m_tmp_tmp);
  loop_ub = static_cast<int32_T>(t) * static_cast<int32_T>(t);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_I[i] = 0.0;
  }
  if (static_cast<int32_T>(t) > 0) {
    st.site = &xc_emlrtRSI;
    if ((1 <= static_cast<int32_T>(t)) &&
        (static_cast<int32_T>(t) > 2147483646)) {
      b_st.site = &u_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (loop_ub = 0; loop_ub < m_tmp_tmp; loop_ub++) {
      b_I[loop_ub + b_I.size(0) * loop_ub] = 1.0;
    }
  }
}

} // namespace coder

// End of code generation (eye.cpp)
