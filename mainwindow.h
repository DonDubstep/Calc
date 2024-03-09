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
    QString term[2];
    int el_num = 0;

private slots:
    void digit_clicked(const QString& num);
    void slotShowAction(const QString& str);


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
