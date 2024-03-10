#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QSignalMapper>


// TODO:
// Сделать обработку вводимого числа (чтоб ноль в начале не был и ограничить число по размеру)
// Отделять 3 цифры запятой на отображении
// Рисовать всё выражение
// Сделать аналогично с другими знаками
// Работать с нецелыми числами
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

void MainWindow::switchTerm()
{
    el_num = el_num == 0 ? 1 : 0;
}

void MainWindow::slotShowAction(const QString& str)
{
    qDebug() << str;
}

void MainWindow::digit_clicked(const QString& num)
{
    display_expression.append(num);
    ui->display->setText(display_expression);
}

void MainWindow::on_symb_plus_clicked()
{
    display_expression.append('+');
    ui->display->setText(display_expression);
}

void MainWindow::take_an_operation(int sign, QString term)
{
    switch(sign)
    {
    case '+':
        result += term.toInt();
        break;
    case '-':
        result -= term.toInt();
        break;
    case '*':
        result *= term.toInt();
        break;
    case '/':
        result /= term.toInt();
        break;
    }
}

void MainWindow::on_symb_equal_clicked()
{
    sign = ' ';
    QString term;
    for(int i = 0; i < display_expression.length(); i++)
    {
        term.append(display_expression[i]);
        if(display_expression[i] == '+')
        {
            if(sign == ' ')
            {
                result = term.toInt();
                sign = '+';
            }
//        else if(display_expression[i] == '-')
//            {
//                if(sign == ' ')
//                {
//                    result = term.toInt();
//                    sign = '-';
//                }
//            }
            else
            {
                take_an_operation(sign, term);
                qDebug() << result;
                term.clear();
            }
        }
    }
    take_an_operation(sign, term);
    term.clear();
    ui->display->setNum(result);
}

