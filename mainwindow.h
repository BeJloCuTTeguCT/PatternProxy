#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "file.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT
    IFile *m_file;
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pb_clicked(bool checked);
};
#endif // MAINWINDOW_H
