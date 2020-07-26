#ifndef GENERATOR_H
#define GENERATOR_H

#include <QVector>

class Generator{
    QVector<QVector<QPair<int,int>>> data;
    int matrix[8][8] = {{0}};

    void recCalc(int row = 0);
    bool check(int row, int col) const;

    void saveMatrix();

public:
    Generator();
    QVector<QPair<int,int>> getResult(int i) const;
};

#endif // GENERATOR_H
