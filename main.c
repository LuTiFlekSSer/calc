#include <stdio.h>
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "complex.h"
#include "struct.h"
#include "solve.h"
#include "pars.h"

#define and &&
#define or ||

int main() {
    char inptt[10000], custper[10000][1000], temp[1000];
    int sper = 3, kolper = 0, ochrl = 0, ist = 0, ochrlp = 0, istp, eqf, s, l, w;
    st ocher[10000], resh[10000], ocherp[10000], reshp[10000], lper[10000];
    lper[0].inf = 1, lper[0].znach = M_PI;
    strcpy(lper[0].deis, "PI");
    lper[1].inf = 1, lper[1].znach = M_E;
    strcpy(lper[1].deis, "e");
    lper[2].inf = 1, lper[2].znach = 0 + 1 * I;
    strcpy(lper[2].deis, "j");
    printf("Enter the expression:\n");
    gets(inptt);
    pars(ocher, lper, &kolper, &sper, inptt, &ochrl);
    if (kolper > 0) {
        printf("Enter variables:\n");
        for (int i = 0; i < kolper; ++i) {
            l = 0;
            gets(custper[i]);
            s = (int) strlen(custper[i]);
            for (int j = 0; j < s; ++j)
                if (custper[i][j] != ' ')
                    custper[i][l++] = custper[i][j];
            custper[i][l] = '\0';
            s = l, eqf = 0, w = 0;
            for (int j = 0; j < s; ++j)
                if (custper[i][j] == '=') {
                    eqf = j;
                    break;
                }
            for (int k = eqf + 1; k < s; ++k)
                temp[w++] = custper[i][k];
            temp[w] = '\0';
            if (eqf > 0) {
                pars(ocherp, lper, &kolper, &sper, temp, &ochrlp);
            } else {
                printf("Incorrect variable entry\n");
                exit(0);
            }
        }
        for (int i = kolper - 1; i >= 0; --i) {
            eqf = 0, l = 0, s = (int) strlen(custper[i]);
            for (int j = 0; j < s; ++j) {
                if (custper[i][j] == '=') {
                    eqf = j;
                    break;
                }
                temp[l++] = custper[i][j];
            }
            temp[l] = '\0';
            if (eqf > 0)
                for (int j = 3; j < sper; ++j)
                    if (strcmp(lper[j].deis, temp) == 0) {
                        w = 0;
                        for (int k = eqf + 1; k < s; ++k)
                            temp[w++] = custper[i][k];
                        temp[w] = '\0';
                        ochrlp = 0, istp = 0;
                        pars(ocherp, lper, &kolper, &sper, temp, &ochrlp);
                        solve(ocherp, &ochrlp, lper, &sper, reshp, &istp);
                        lper[j].znach = reshp[istp - 1].znach, lper[j].inf = 1;
                        break;
                    }
        }
    }
    solve(ocher, &ochrl, lper, &sper, resh, &ist);
    printf("Answer: ");
    if (isinf(creal(resh[ist - 1].znach)))
        printf("Inf\n");
    else if (isnan(creal(resh[ist - 1].znach)))
        printf("Nan\n");
    else {
        if (fabs(creal(resh[ist - 1].znach)) == 0)
            printf("(0");
        else
            printf("(%g", creal(resh[ist - 1].znach));
        if (fabs(cimag(resh[ist - 1].znach)) == 0)
            printf(")\n");
        else
            printf(";%gj)\n", cimag(resh[ist - 1].znach));
    }
    return 0;
}