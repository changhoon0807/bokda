//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// gammaln.cpp
//
// Code generation for function 'gammaln'
//

// Include files
#include "gammaln.h"
#include "Gen_Gamma_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo f_emlrtRSI{
    10,        // lineNo
    "gammaln", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    17,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunctionInPlace.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    121,              // lineNo
    "scalar_gammaln", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    129,              // lineNo
    "scalar_gammaln", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    138,              // lineNo
    "scalar_gammaln", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    179,              // lineNo
    "scalar_gammaln", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pathName
};

static emlrtRTEInfo b_emlrtRTEI{
    117,              // lineNo
    5,                // colNo
    "scalar_gammaln", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2021a\\toolbox\\eml\\lib\\matlab\\specfun\\gammaln.m" // pName
};

// Function Definitions
namespace coder {
void gammaln(const emlrtStack *sp, real_T *x)
{
  static const real_T table100[100]{0.0,
                                    0.0,
                                    0.69314718055994529,
                                    1.791759469228055,
                                    3.1780538303479458,
                                    4.7874917427820458,
                                    6.5792512120101012,
                                    8.5251613610654147,
                                    10.604602902745251,
                                    12.801827480081469,
                                    15.104412573075516,
                                    17.502307845873887,
                                    19.987214495661885,
                                    22.552163853123425,
                                    25.19122118273868,
                                    27.89927138384089,
                                    30.671860106080672,
                                    33.505073450136891,
                                    36.395445208033053,
                                    39.339884187199495,
                                    42.335616460753485,
                                    45.380138898476908,
                                    48.471181351835227,
                                    51.606675567764377,
                                    54.784729398112319,
                                    58.003605222980518,
                                    61.261701761002,
                                    64.557538627006338,
                                    67.88974313718154,
                                    71.257038967168015,
                                    74.658236348830158,
                                    78.0922235533153,
                                    81.557959456115043,
                                    85.054467017581516,
                                    88.580827542197682,
                                    92.1361756036871,
                                    95.7196945421432,
                                    99.330612454787428,
                                    102.96819861451381,
                                    106.63176026064346,
                                    110.32063971475739,
                                    114.03421178146171,
                                    117.77188139974507,
                                    121.53308151543864,
                                    125.3172711493569,
                                    129.12393363912722,
                                    132.95257503561632,
                                    136.80272263732635,
                                    140.67392364823425,
                                    144.5657439463449,
                                    148.47776695177302,
                                    152.40959258449735,
                                    156.3608363030788,
                                    160.3311282166309,
                                    164.32011226319517,
                                    168.32744544842765,
                                    172.35279713916279,
                                    176.39584840699735,
                                    180.45629141754378,
                                    184.53382886144948,
                                    188.6281734236716,
                                    192.7390472878449,
                                    196.86618167289,
                                    201.00931639928152,
                                    205.1681994826412,
                                    209.34258675253685,
                                    213.53224149456327,
                                    217.73693411395422,
                                    221.95644181913033,
                                    226.1905483237276,
                                    230.43904356577696,
                                    234.70172344281826,
                                    238.97838956183432,
                                    243.26884900298271,
                                    247.57291409618688,
                                    251.89040220972319,
                                    256.22113555000954,
                                    260.56494097186322,
                                    264.92164979855278,
                                    269.29109765101981,
                                    273.67312428569369,
                                    278.06757344036612,
                                    282.4742926876304,
                                    286.893133295427,
                                    291.32395009427029,
                                    295.76660135076065,
                                    300.22094864701415,
                                    304.68685676566872,
                                    309.1641935801469,
                                    313.65282994987905,
                                    318.1526396202093,
                                    322.66349912672615,
                                    327.1852877037752,
                                    331.71788719692847,
                                    336.26118197919845,
                                    340.815058870799,
                                    345.37940706226686,
                                    349.95411804077025,
                                    354.53908551944079,
                                    359.1342053695754};
  static const real_T p1[8]{4.9452353592967269, 201.8112620856775,
                            2290.8383738313464, 11319.672059033808,
                            28557.246356716354, 38484.962284437934,
                            26377.487876241954, 7225.8139797002877};
  static const real_T p2[8]{4.974607845568932,     542.4138599891071,
                            15506.938649783649,    184793.29044456323,
                            1.0882047694688288E+6, 3.33815296798703E+6,
                            5.1066616789273527E+6, 3.0741090548505397E+6};
  static const real_T p4[8]{14745.0216605994,       2.4268133694867045E+6,
                            1.2147555740450932E+8,  2.6634324496309772E+9,
                            2.9403789566345539E+10, 1.7026657377653989E+11,
                            4.926125793377431E+11,  5.6062518562239514E+11};
  static const real_T q1[8]{67.482125503037778, 1113.3323938571993,
                            7738.7570569353984, 27639.870744033407,
                            54993.102062261576, 61611.221800660023,
                            36351.2759150194,   8785.5363024310136};
  static const real_T q2[8]{183.03283993705926,    7765.0493214450062,
                            133190.38279660742,    1.1367058213219696E+6,
                            5.2679641174379466E+6, 1.3467014543111017E+7,
                            1.7827365303532742E+7, 9.5330955918443538E+6};
  static const real_T q4[8]{2690.5301758708993,     639388.56543000927,
                            4.1355999302413881E+7,  1.120872109616148E+9,
                            1.4886137286788137E+10, 1.0168035862724382E+11,
                            3.4174763455073773E+11, 4.4631581874197131E+11};
  static const real_T c[7]{-0.001910444077728,      0.00084171387781295,
                           -0.00059523799130430121, 0.0007936507935003503,
                           -0.0027777777777776816,  0.083333333333333329,
                           0.0057083835261};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &g_emlrtRSI;
  if (!muDoubleScalarIsNaN(*x)) {
    if (*x < 0.0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
                                    "MATLAB:gammaln:negativeVal",
                                    "MATLAB:gammaln:negativeVal", 0);
    } else if (*x > 2.55E+305) {
      *x = rtInf;
    } else if (*x <= 2.2204460492503131E-16) {
      c_st.site = &h_emlrtRSI;
      if (*x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
      }
      *x = -muDoubleScalarLog(*x);
    } else if (*x <= 0.5) {
      real_T r;
      real_T t;
      t = 1.0;
      r = 0.0;
      for (int32_T i{0}; i < 8; i++) {
        r = r * *x + p1[i];
        t = t * *x + q1[i];
      }
      c_st.site = &i_emlrtRSI;
      if (*x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
      }
      *x = -muDoubleScalarLog(*x) + *x * (*x * (r / t) + -0.57721566490153287);
    } else if (*x <= 0.6796875) {
      real_T r;
      real_T t;
      t = 1.0;
      r = 0.0;
      for (int32_T i{0}; i < 8; i++) {
        r = r * ((*x - 0.5) - 0.5) + p2[i];
        t = t * ((*x - 0.5) - 0.5) + q2[i];
      }
      c_st.site = &j_emlrtRSI;
      if (*x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
      }
      *x = -muDoubleScalarLog(*x) +
           ((*x - 0.5) - 0.5) *
               (((*x - 0.5) - 0.5) * (r / t) + 0.42278433509846713);
    } else if ((*x == muDoubleScalarFloor(*x)) && (*x <= 100.0)) {
      *x = table100[static_cast<int32_T>(*x) - 1];
    } else if (*x <= 1.5) {
      real_T r;
      real_T t;
      t = 1.0;
      r = 0.0;
      for (int32_T i{0}; i < 8; i++) {
        r = r * ((*x - 0.5) - 0.5) + p1[i];
        t = t * ((*x - 0.5) - 0.5) + q1[i];
      }
      *x = ((*x - 0.5) - 0.5) *
           (((*x - 0.5) - 0.5) * (r / t) + -0.57721566490153287);
    } else if (*x <= 4.0) {
      real_T r;
      real_T t;
      t = 1.0;
      r = 0.0;
      for (int32_T i{0}; i < 8; i++) {
        r = r * (*x - 2.0) + p2[i];
        t = t * (*x - 2.0) + q2[i];
      }
      *x = (*x - 2.0) * ((*x - 2.0) * (r / t) + 0.42278433509846713);
    } else if (*x <= 12.0) {
      real_T r;
      real_T t;
      t = -1.0;
      r = 0.0;
      for (int32_T i{0}; i < 8; i++) {
        r = r * (*x - 4.0) + p4[i];
        t = t * (*x - 4.0) + q4[i];
      }
      *x = (*x - 4.0) * (r / t) + 1.791759469228055;
    } else {
      real_T r;
      real_T t;
      if (*x <= 2.25E+76) {
        r = 0.0057083835261;
        t = 1.0 / (*x * *x);
        for (int32_T i{0}; i < 6; i++) {
          r = r * t + c[i];
        }
        r /= *x;
      } else {
        r = 0.0;
      }
      c_st.site = &k_emlrtRSI;
      if (*x < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &c_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
      }
      t = muDoubleScalarLog(*x);
      *x = ((r + 0.91893853320467278) - 0.5 * t) + *x * (t - 1.0);
    }
  }
}

} // namespace coder

// End of code generation (gammaln.cpp)
