#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QSignalMapper>


// TODO:
// Сделать обработку вводимого числа (чтоб ноль в начале не был и ограничить число по размеру)
// После нажатия на знаки менять элемент массива числа
// Преобразовать в int и вывести результат
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Переопределяем сигналы нажатия на кнопку так, чтоб передавался текст на кнопке
    QSignalMapper* psigMapperDigit = new QSignalMapper(this);
    connect(psigMapperDigit, SIGNAL(mappedString(const QString&)),
            this, SLOT(digit_clicked(const QString&))
            );

    // Перенаправление всех кнопок в один слот
    connect(ui->digit_0, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_0, "0");
    connect(ui->digit_1, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_1, "1");
    connect(ui->digit_2, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_2, "2");
    connect(ui->digit_3, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_3, "3");
    connect(ui->digit_4, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_4, "4");
    connect(ui->digit_5, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_5, "5");
    connect(ui->digit_6, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_6, "6");
    connect(ui->digit_7, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_7, "7");
    connect(ui->digit_8, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_8, "8");
    connect(ui->digit_9, SIGNAL(clicked()), psigMapperDigit, SLOT(map()));
    psigMapperDigit->setMapping(ui->digit_9, "9");
//    connect(ui->digit_0, SIGNAL(clicked()), SLOT(digit_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowAction(const QString& str)
{
    qDebug() << str;
}

void MainWindow::digit_clicked(const QString& num)
{
    term[el_num].append(num);
    ui->display->setText(term[el_num]);
}
