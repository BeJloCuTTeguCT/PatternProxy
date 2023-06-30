#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , m_file(new File)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::pb_clicked);
    ui->pushButton->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pb_clicked(bool checked)
{
    if(checked) {
        delete m_file;
        m_file = new ProxyFile;
        ui->textEdit->setText(m_file->fileDataStr("../PatternProxy/file.txt"));
    }
    else {
        delete m_file;
        m_file = new File;
        ui->textEdit->setText(m_file->fileDataStr("../PatternProxy/file.txt"));
    }
}

