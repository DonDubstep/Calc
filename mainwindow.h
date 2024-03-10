#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QObject>
#include <QPushButton>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString display_expression;
    int el_num = 0;
    char sign;
    int result = 0;
    void switchTerm();
    void take_an_operation(int, QString);

private slots:
    void digit_clicked(const QString& num);
    void slotShowAction(const QString& str);


    void on_symb_plus_clicked();

    void on_symb_equal_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
