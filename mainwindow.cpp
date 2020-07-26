#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>

#include "generator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setMinimumSize(410, 474);
    setMaximumSize(410, 474);

    setWindowFlags( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderChanged(int)));

    QGridLayout *lt = static_cast<QGridLayout*>(ui->fr->layout());
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            QLabel *lb = new QLabel();
            lb->setAlignment(Qt::AlignCenter);
            lb->setStyleSheet(QStringLiteral("background-color:") + (((i+j)%2)?("gray"):("white")) + ";padding: 5px;");
            lt->addWidget(lb, i, j);
        }
    }

    gen = new Generator();
    updateTable(0);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::sliderChanged(int newValue){
    ui->label->setText(QString::number(newValue + 1) + " / 92");
    updateTable(newValue);
}

void MainWindow::updateTable(int pos){
    QVector<QPair<int,int>> matrix = gen->getResult(pos);
    QGridLayout *lt = static_cast<QGridLayout*>(ui->fr->layout());
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            static_cast<QLabel*>(lt->itemAtPosition(i, j)->widget())->setPixmap(QPixmap());

    for (QPair<int,int> &pair: matrix) {
        static_cast<QLabel*>(lt->itemAtPosition(pair.first, pair.second)->widget())->setPixmap(
                    QPixmap(":/img/queen.png").scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

}
