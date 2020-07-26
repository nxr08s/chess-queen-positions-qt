#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QPropertyAnimation;
class Generator;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Generator *gen;

    void updateTable(int);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void sliderChanged(int);

};

#endif // MAINWINDOW_H
