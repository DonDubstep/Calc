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


private slots:
    void digit_clicked(const QString& num);

    void on_symb_equal_clicked();
    QString parse(QString disp_expr);

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
