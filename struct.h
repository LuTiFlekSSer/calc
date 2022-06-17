
#ifndef PROJECT1_STRUCT_H
#define PROJECT1_STRUCT_H

#include "complex.h"

typedef struct st {
    int inf;//0-действие 1-вещ. число 2-мнимая часть 3-переменная 4-функция //если лист переменных, то 0-не посчитанно 1-посчитанно
    char deis[1000];//или название
    double complex znach;
} st;
#endif
