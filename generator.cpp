#include "generator.h"

#include <iostream>

// recursive func to get all arrangements
void Generator::recCalc(int row){
    // if last row reached, no conflict with other queens and save current arrangement
    if (row == 8){
        saveMatrix();
        return;
    }

    // check arrangements with queen in each colomn in current row
    int currentCol = 0;
    while (currentCol < 8){
        if (check(row, currentCol)){
            matrix[row][currentCol] = 1;
            recCalc(row + 1);
            matrix[row][currentCol] = 0;
        }
        currentCol++;
    }
}

bool Generator::check(int row, int col) const{
    // check if any queen above in colomn
    for (int i = 0; i < row; i++)
        if (matrix[i][col]) return false;

    // check diagonal from top left corner
    for (int x = col - 1, y = row - 1; x >= 0 && y >= 0; x--, y--)
        if (matrix[y][x]) return false;

    // check diagonal from top right corner
    for (int x = col + 1, y = row - 1; x < 8 && y >= 0; x++, y--)
        if (matrix[y][x]) return false;

    // no need to check row, because only 1 queen can be placed in current row

    return true;
}

// add current arrangement to list of possible arrangements
void Generator::saveMatrix(){
    QVector<QPair<int,int>> newData;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (matrix[i][j])
                newData.append(QPair<int, int>(i, j));

    data.append(newData);
}

Generator::Generator(){
    recCalc();
}

QVector<QPair<int, int> > Generator::getResult(int i) const{
    return data[i];
}
