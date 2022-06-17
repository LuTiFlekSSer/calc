#include "pars.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define and &&
#define or ||

void pars(st *ocher, st *lper, int *kolper, int *sper, char *inptt, int *ochrl) {
    char inpt[10000], temp[1000];
    st inps[10000];
    int ll = (int) strlen((inptt)), pr = 0, prz = 0, l = 0, sinpsr = 0;
    if (ll == 0) {
        printf("Syntax error\n");
        exit(0);
    } else if (ll > 9996) {
        printf("Ni-chan, it's too long\n");
        exit(0);
    }
    for (int i = 0; i < ll; ++i)
        if ((inptt)[i] != ' ')
            inptt[l++] = inptt[i];
    inptt[l] = '\0';
    ll = l, l = 0;
    for (int i = 0; i < ll; ++i) {
        if (!((inptt[i] >= 'a' and inptt[i] <= 'z') or (inptt[i] >= 'A' and inptt[i] <= 'Z') or (
                inptt[i] >= '0' and inptt[i] <= '9') or inptt[i] == '/' or inptt[i] == '*' or inptt[i] == '-' or
              inptt[i] == '+' or inptt[i] == '^' or inptt[i] == ',' or inptt[i] == '(' or inptt[i] == ')' or inptt[i] ==
                                                                                                             '.')) {
            printf("Syntax error\n");
            exit(0);
        }
        if ((inptt)[i] == 'p' and inptt[i + 1] == 'o' and inptt[i + 2] == 'w' and inptt[i + 3] == '(')
            ++prz;
        if ((inptt)[i] == 'l' and inptt[i + 1] == 'o' and inptt[i + 2] == 'g' and inptt[i + 3] == '(')
            ++prz;
        if ((inptt)[i] == ',')
            --prz;
        if ((inptt)[i] == '(')
            ++pr;
        if ((inptt)[i] == ')')
            --pr;
        if (((inptt)[i] == '/' and inptt[i + 1] == '/') or ((inptt)[i] == '/' and inptt[i + 1] == '*') or (
                inptt[i] == '/' and inptt[i + 1] == '+') or ((inptt)[i] == '/' and inptt[i + 1] == '-') or (
                    inptt[i] == '/' and inptt[i + 1] == '^') or ((inptt)[i] == '/' and inptt[i + 1] == ',') or (
                    inptt[i] == '*' and inptt[i + 1] == '*') or ((inptt)[i] == '*' and inptt[i + 1] == '/') or (
                    inptt[i] == '*' and inptt[i + 1] == '+') or ((inptt)[i] == '*' and inptt[i + 1] == '-') or (
                    inptt[i] == '*' and inptt[i + 1] == '^') or ((inptt)[i] == '*' and inptt[i + 1] == ',') or (
                    inptt[i] == '+' and inptt[i + 1] == '/') or ((inptt)[i] == '+' and inptt[i + 1] == '*') or (
                    inptt[i] == '+' and inptt[i + 1] == '+') or ((inptt)[i] == '+' and inptt[i + 1] == '-') or (
                    inptt[i] == '+' and inptt[i + 1] == '^') or ((inptt)[i] == '+' and inptt[i + 1] == ',') or (
                    inptt[i] == '-' and inptt[i + 1] == '-') or ((inptt)[i] == '-' and inptt[i + 1] == '*') or (
                    inptt[i] == '-' and inptt[i + 1] == '+') or ((inptt)[i] == '-' and inptt[i + 1] == '/') or (
                    inptt[i] == '-' and inptt[i + 1] == '^') or ((inptt)[i] == '-' and inptt[i + 1] == ',') or (
                    inptt[i] == '^' and inptt[i + 1] == '/') or ((inptt)[i] == '^' and inptt[i + 1] == '*') or (
                    inptt[i] == '^' and inptt[i + 1] == '+') or ((inptt)[i] == '^' and inptt[i + 1] == '-') or (
                    inptt[i] == '^' and inptt[i + 1] == '^') or ((inptt)[i] == '^' and inptt[i + 1] == ',') or (
                    inptt[i] == ',' and inptt[i + 1] == '/') or ((inptt)[i] == ',' and inptt[i + 1] == '*') or (
                    inptt[i] == ',' and inptt[i + 1] == '+') or (inptt[i] == ',' and inptt[i + 1] == '^') or (
                    (inptt)[i] == ',' and inptt[i + 1] == ',') or (
                    inptt[i] == '(' and inptt[i + 1] == ')') or prz < 0 or pr < 0 or ((inptt)[i] == '/' and i == 0) or (
                    inptt[i] == '*' and i == 0) or ((inptt)[i] == '+' and i == 0) or ((inptt)[i] == '^' and i == 0) or (
                    inptt[i] == '(' and inptt[i + 1] == ',') or ((inptt)[i] == ',' and inptt[i + 1] == ')') or (
                    inptt[i] == '(' and inptt[i + 1] == '+') or ((inptt)[i] == '(' and inptt[i + 1] == '^') or (
                    inptt[i] == '(' and inptt[i + 1] == '/') or ((inptt)[i] == '(' and inptt[i + 1] == '*') or (
                    inptt[i] == '/' and i == ll - 1) or ((inptt)[i] == '.' and inptt[i + 1] == '.') or (
                    inptt[i] == '*' and i == ll - 1) or ((inptt)[i] == '+' and i == ll - 1) or (
                    inptt[i] == '^' and i == ll - 1) or ((inptt)[i] == '-' and i == ll - 1)) {
            printf("Syntax error\n");
            exit(0);
        }
    }
    if (pr != 0 or prz != 0) {
        printf("Syntax error\n");
        exit(0);
    }
    for (int i = 0; i < ll; ++i) {
        if (i == 0 and inptt[i] == '-')
            inpt[l++] = '0';
        if (i > 0 and inptt[i - 1] == '(' and inptt[i] == '-')
            inpt[l++] = '0';
        if (i > 0 and inptt[i - 1] == ',' and inptt[i] == '-')
            inpt[l++] = '0';
        if (inptt[i - 1] == ')' and ((inptt[i] >= 'a' and inptt[i] <= 'z') or (inptt[i] >= 'A' and inptt[i] <= 'Z') or (
                inptt[i] >= '0' and inptt[i] <= '9')))
            inpt[l++] = '*';
        inpt[l++] = inptt[i];
    }
    inpt[l] = '\0';
    int q = l, fl = -1, templ = 0, i = 0;
    while (i < q) {
        if (fl == -1 or fl == 0) {
            if (inpt[i] >= '0' and inpt[i] <= '9' and inpt[i + 1] <= '9' and inpt[i + 1] >= '0') {
                temp[templ++] = inpt[i];
                ++i;
                fl = 0;
                continue;
            } else if ((inpt[i] >= '0' and inpt[i] <= '9') or inpt[i] == '.') {
                temp[templ++] = inpt[i];
                if (((inpt[i + 1] >= 'a' and inpt[i + 1] <= 'z') or (inpt[i + 1] >= 'A' and inpt[i + 1] <= 'Z') or
                     inpt[i + 1] == '(') and inpt[i + 1] != 'j') {
                    printf("Syntax error\n");
                    exit(0);
                }
                if (inpt[i + 1] == '.' or inpt[i] == '.') {
                    ++i;
                    continue;
                }
                for (int j = 0; j < templ; ++j)
                    ocher[(*ochrl)].deis[j] = temp[j];
                ocher[(*ochrl)].deis[templ] = '\0';
                ocher[(*ochrl)].inf = 1;
                if (inpt[i + 1] == 'j' and !((inpt[i + 2] >= 'a' and inpt[i + 2] <= 'z') or (
                        inpt[i + 2] >= 'A' and inpt[i + 2] <= 'Z') or (inpt[i + 2] >= '0' and inpt[i + 2] <= '9') or
                                             inpt[i + 2] == '(')) {
                    ocher[(*ochrl)].deis[templ] = 'j';
                    ocher[(*ochrl)].deis[templ + 1] = '\0';
                    ++i;
                    ocher[(*ochrl)].inf = 2;
                } else if (inpt[i + 1] == 'j' and ((inpt[i + 2] >= 'a' and inpt[i + 2] <= 'z') or (
                        inpt[i + 2] >= 'A' and inpt[i + 2] <= 'Z') or (inpt[i + 2] >= '0' and inpt[i + 2] <= '9') or
                                                   inpt[i + 2] == '(')) {
                    printf("Syntax error\n");
                    exit(0);
                }
                ++(*ochrl);
                templ = 0;
                ++i;
                fl = -1;
                continue;
            }
        }
        if (fl == -1 or fl == 1) {
            if (((inpt[i] >= 'a' and inpt[i] <= 'z') or (inpt[i] >= 'A' and inpt[i] <= 'Z') or (
                    inpt[i] >= '0' and inpt[i] <= '9')) and (
                        (inpt[i + 1] >= 'a' and inpt[i + 1] <= 'z') or (
                                inpt[i + 1] >= 'A' and inpt[i + 1] <=
                                                       'Z') or (
                                inpt[i + 1] <= '9' and inpt[i + 1] >= '0'))) {
                fl = 1;
                temp[templ++] = inpt[i];
                ++i;
                continue;
            } else if ((inpt[i] >= 'a' and inpt[i] <= 'z') or (inpt[i] >= 'A' and inpt[i] <= 'Z') or (
                    inpt[i] >= '0' and inpt[i] <= '9')) {
                fl = -1;
                temp[templ++] = inpt[i];
                if (inpt[i + 1] == '(') {
                    temp[templ++] = '(';
                    for (int j = 0; j < templ; ++j)
                        inps[sinpsr].deis[j] = temp[j];
                    inps[sinpsr].deis[templ] = '\0';
                    ++sinpsr;
                    ++i;
                } else {
                    temp[templ] = '\0';
                    if (strcmp(temp, "PI") != 0 and strcmp(temp, "e") != 0 and strcmp(temp, "j") != 0) {
                        int fll = 0;
                        for (int j = 3; j < *sper; ++j)
                            if (strcmp(temp, lper[j].deis) == 0) {
                                fll = 1;
                                break;
                            }
                        if (fll == 0) {
                            if (*kolper == 9999) {
                                printf("Exceeded the number of variables\n");
                                exit(0);
                            }
                            ++(*kolper);
                            lper[(*sper)].inf = 0;
                            for (int j = 0; j < templ; ++j)
                                lper[(*sper)].deis[j] = temp[j];
                            lper[(*sper)].deis[templ] = '\0';
                            ++(*sper);
                        }
                        for (int j = 0; j < templ; ++j)
                            ocher[(*ochrl)].deis[j] = temp[j];
                        ocher[(*ochrl)].inf = 3;
                        ocher[(*ochrl)++].deis[templ] = '\0';
                    } else {
                        for (int j = 0; j < templ; ++j)
                            ocher[(*ochrl)].deis[j] = temp[j];
                        ocher[(*ochrl)].inf = 3;
                        ocher[(*ochrl)++].deis[templ] = '\0';
                    }
                }
                ++i;
                templ = 0;
                continue;
            }
        }
        if (inpt[i] == ',') {
            while (1) {
                if (sinpsr - 1 < 0) {
                    printf("Syntax error\n");
                    exit(0);
                }
                if (inps[sinpsr - 1].deis[strlen(inps[sinpsr - 1].deis) - 1] == '(')
                    break;
                ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                ocher[(*ochrl)].inf = 0;
                ocher[(*ochrl)++].deis[1] = '\0';
                --sinpsr;
            }
            ++i;
            continue;
        }
        if (inpt[i] == '^' or inpt[i] == '*' or inpt[i] == '/' or inpt[i] == '+' or inpt[i] == '-') {
            while (1) {
                if (sinpsr - 1 < 0)
                    break;
                if (inpt[i] == '-' and (
                        inps[sinpsr - 1].deis[0] == '+' or inps[sinpsr - 1].deis[0] == '/' or
                        inps[sinpsr - 1].deis[0] ==
                        '*' or
                        inps[sinpsr - 1].deis[0] == '^' or inps[sinpsr - 1].deis[0] == '-')) {
                    ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                    ocher[(*ochrl)].inf = 0;
                    ocher[(*ochrl)++].deis[1] = '\0';
                    --sinpsr;
                    continue;
                }
                if (inpt[i] == '+' and (
                        inps[sinpsr - 1].deis[0] == '+' or inps[sinpsr - 1].deis[0] == '/' or
                        inps[sinpsr - 1].deis[0] ==
                        '*' or
                        inps[sinpsr - 1].deis[0] == '^' or inps[sinpsr - 1].deis[0] == '-')) {
                    ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                    ocher[(*ochrl)].inf = 0;
                    ocher[(*ochrl)++].deis[1] = '\0';
                    --sinpsr;
                    continue;
                }
                if (inpt[i] == '/' and (inps[sinpsr - 1].deis[0] == '/' or inps[sinpsr - 1].deis[0] ==
                                                                           '*' or
                                        inps[sinpsr - 1].deis[0] == '^')) {
                    ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                    ocher[(*ochrl)].inf = 0;
                    ocher[(*ochrl)++].deis[1] = '\0';
                    --sinpsr;
                    continue;
                }
                if (inpt[i] == '*' and (inps[sinpsr - 1].deis[0] ==
                                        '*' or
                                        inps[sinpsr - 1].deis[0] == '^' or inps[sinpsr - 1].deis[0] == '/')) {
                    ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                    ocher[(*ochrl)].inf = 0;
                    ocher[(*ochrl)++].deis[1] = '\0';
                    --sinpsr;
                    continue;
                }
                if (inpt[i] == '^' and (inps[sinpsr - 1].deis[0] == '^')) {
                    ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                    ocher[(*ochrl)].inf = 0;
                    ocher[(*ochrl)++].deis[1] = '\0';
                    --sinpsr;
                    continue;
                }
                break;
            }
            inps[sinpsr].deis[0] = inpt[i];
            inps[sinpsr].deis[1] = '\0';
            ++sinpsr;
            ++i;
            continue;
        }
        if (inpt[i] == '(') {
            inps[sinpsr].deis[0] = inpt[i];
            inps[sinpsr].deis[1] = '\0';
            ++sinpsr;
            ++i;
            continue;
        }
        if (inpt[i] == ')') {
            while (1) {
                if (sinpsr - 1 < 0) {
                    printf("Syntax error\n");
                    exit(0);
                }
                if (inps[sinpsr - 1].deis[strlen(inps[sinpsr - 1].deis) - 1] == '(') {
                    if (inps[sinpsr - 1].deis[0] != '(') {
                        for (int j = 0; j < strlen(inps[sinpsr - 1].deis) - 1; ++j)
                            ocher[(*ochrl)].deis[j] = inps[sinpsr - 1].deis[j];
                        ocher[(*ochrl)].inf = 4;
                        ocher[(*ochrl)++].deis[strlen(inps[sinpsr - 1].deis) - 1] = '\0';
                    }
                    --sinpsr;
                    break;
                }
                ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
                ocher[(*ochrl)].inf = 0;
                ocher[(*ochrl)++].deis[1] = '\0';
                --sinpsr;
            }
            ++i;
            continue;
        }
        ++i;
    }
    while (sinpsr - 1 >= 0) {
        if (inps[sinpsr - 1].deis[0] == '(') {
            printf("Syntax error\n");
            exit(0);
        }
        ocher[(*ochrl)].deis[0] = inps[sinpsr - 1].deis[0];
        ocher[(*ochrl)].inf = 0;
        ocher[(*ochrl)++].deis[1] = '\0';
        --sinpsr;
    }
}