#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QSignalMapper>
#include <string.h>
// TODO:
// Отделять 3 цифры запятой на отображении
// Рисовать всё выражение
// Сделать аналогично с другими знаками
// Работать с нецелыми числами
// Сделать обработку вводимого числа (чтоб ноль в начале не был и ограничить число по размеру)
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
// Алгоритм написан, осталось отыскать багу логами (повыводи Stack и отследи его состояние)
QString MainWindow::parse(QString disp_expr)
{
    QStringList Stack;
    auto len = disp_expr.length();
    QString cur_str;
    int i;
    QChar last_sign;
    for(i = 0; i < len; i++)
    {
        for(int k = 0; k < Stack.length(); k++)
        {
            qDebug() << Stack[k];
        }
        if (disp_expr[i] >= QChar('0') && disp_expr[i] <= QChar('9'))
        {
            cur_str.append(disp_expr[i]);
            continue;
        }
        if (disp_expr[i] == '+' || disp_expr[i] == '-' || disp_expr[i] == '*' || disp_expr[i] == '/')
        {
            if(Stack.length() < 3)
            {
                Stack.append(cur_str);
                cur_str.clear();
                Stack.append(cur_str);
                last_sign = disp_expr[i];
                continue;
            }
            if ((disp_expr[i] == '*' || disp_expr[i] == '/') && (last_sign == '+' || last_sign == '-'))
            {
                Stack.append(cur_str);
            }
            else
            {
                int last = Stack.back().toInt();
                Stack.pop_back();
                int cur = cur_str.toInt();
                char cur_sign = Stack.back().toStdString()[0];
                Stack.pop_back();
                switch(cur_sign)
                {
                case '+': Stack.append(QString::number(last + cur)); break;
                case '-': Stack.append(QString::number(last - cur)); break;
                case '*': Stack.append(QString::number(last * cur)); break;
                case '/': Stack.append(QString::number(last / cur)); break;
                }
            }
            cur_str.clear();
            Stack.append(disp_expr[i]);
        }
    }
    while(Stack.length() > 1)
    {
        int lastval = Stack.back().toInt();
        Stack.pop_back();
        char cur_sign = Stack.back().toStdString()[0];
        int result;
        switch(cur_sign)
        {
        case '+': result = Stack.back().toInt() + lastval; break;
        case '-': result = Stack.back().toInt() - lastval; break;
        case '*': result = Stack.back().toInt() * lastval; break;
        case '/': result = Stack.back().toInt() / lastval; break;
        }
        Stack.pop_back();
        Stack.push_back(QString::number(result));
    }
    return Stack.back();
}

void MainWindow::digit_clicked(const QString& num)
{
    if(display_expression == "0" && num == "0")
        return;
    display_expression.append(num);
    ui->display->setText(display_expression);
}

void MainWindow::on_symb_equal_clicked()
{
    qDebug() << "Equal";
    QString temp_expr  = "10+5*2+9";
    qDebug() << parse(temp_expr);
}

