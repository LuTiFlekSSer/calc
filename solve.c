#include "solve.h"
#include "string.h"
#include "complex.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#define and &&
#define or ||

complex double cabobus(complex double a) {
    return cabs(a) + 0 * I;
}

complex double creol(complex double a) {
    return creal(a) + 0 * I;
}

complex double cimog(complex double a) {
    return cimag(a) + 0 * I;
}

complex double mag(complex double a) {
    return cabs(a) + 0 * I;
}

complex double phase(complex double a) {
    double w = 0;
    if (creal(a) < 0 and cimag(a) >= 0)
        w = M_PI;
    else if (creal(a) < 0 and cimag(a) < 0)
        w = -M_PI;
    return catan(cimag(a) / creal(a)) + w;
}

complex double sum(complex double a, complex double b) {
    return a + b;
}

complex double raz(complex double a, complex double b) {
    return a - b;
}

complex double del(complex double a, complex double b) {
    return a / b;
}

complex double umn(complex double a, complex double b) {
    return a * b;
}

complex double step(complex double a, complex double b) {
    if (fabs(cimag(a)) == 0 and fabs(cimag(b)) == 0 and creal(a) < 0 and fabs(creal(b)) - (int) fabs(creal(b)) == 0 and
        (int) fabs(creal(b)) % 2 == 0)
        return pow(creal(a), creal(b)) + 0 * I;
    else
        return cpow(a, b);
}

complex double loog(complex double b, complex double a) {
    return clog(a) / clog(b);
}

void solve(st *ocher, const int *ochrl, st *lper, const int *sper, st *resh, int *ist) {
    complex double (*unfuncs[])(complex double) ={ccos, csin, ctan, clog, csqrt, cabobus, cexp,
                                                  creol, cimog, mag, phase};
    char *unf[] = {"cos", "sin", "tg", "ln", "sqrt", "abs", "exp",
                   "real", "imag", "mag", "phase"};
    complex double (*binfuncs[])(complex double, complex double) ={sum, raz, del, umn, step, step,
                                                                   loog};
    char *binf[] = {"+", "-", "/", "*", "^", "pow", "log"};
    int i = 0;
    double complex tmp;
    while (i < (*ochrl)) {
        tmp = 0 + 0 * I;
        if (ocher[i].inf == 1) {
            resh[(*ist)].znach = 0 + 0 * I;
            sscanf_s(ocher[i].deis, "%lf", &tmp);
            resh[(*ist)++].znach += tmp;
        } else if (ocher[i].inf == 2) {
            resh[(*ist)].znach = 0 + 0 * I;
            sscanf_s(ocher[i].deis, "%lf", &tmp);
            resh[(*ist)++].znach += tmp * I;
        } else if (ocher[i].inf == 0) {
            for (int j = 0; j < 5; ++j)
                if (ocher[i].deis[0] == binf[j][0]) {
                    resh[(*ist) - 2].znach = binfuncs[j](resh[(*ist) - 2].znach, resh[(*ist) - 1].znach);
                    --(*ist);
                    break;
                }
        } else if (ocher[i].inf == 4) {
            int gl = 0;
            for (int j = 0; j < 11; ++j)
                if (strcmp(ocher[i].deis, unf[j]) == 0) {
                    resh[(*ist) - 1].znach = unfuncs[j](resh[(*ist) - 1].znach);
                    gl = 1;
                    break;
                } else if ((j == 6 or j == 5) and strcmp(ocher[i].deis, binf[j]) == 0) {
                    resh[(*ist) - 2].znach = binfuncs[j](resh[(*ist) - 2].znach, resh[(*ist) - 1].znach);
                    --(*ist);
                    gl = 1;
                    break;
                }
            if (!gl) {
                printf("Function error\n");
                exit(0);
            }
        } else if (ocher[i].inf == 3) {
            resh[(*ist)].znach = 0 + 0 * I;
            for (int j = 0; j < (*sper); ++j)
                if (strcmp(lper[j].deis, ocher[i].deis) == 0) {
                    if (lper[j].inf == 1) {
                        tmp = lper[j].znach;
                        break;
                    } else {
                        printf("Variable error\n");
                        exit(0);
                    }
                }
            resh[(*ist)++].znach += tmp;
        }
        ++i;
    }
}