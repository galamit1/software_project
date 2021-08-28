//
// Created by galam on 26/07/2021.
//

#include "lnorm.h"

Matrix * run_lnorm(Matrix * wam, Matrix * ddg) {
    Matrix * lnorm = getIdentitiyMatrixSizeN(wam->rows);
    double value;
    for (int i = 0; i < wam->rows; ++i) {
        for (int j = i + 1; j < wam->rows; ++j) {
            value = -1 * wam->cells[i][j] * ddg->cells[i][i] * ddg->cells[j][j];
            lnorm->cells[i][j] = value;
            lnorm->cells[j][i] = value;
        }
    }
    return lnorm;
}