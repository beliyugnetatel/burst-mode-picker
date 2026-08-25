#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFolderbtn_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select Images",
        QDir::homePath(),
        "Images (*jpg)");

    for (const QString $file : files)
    {

    }
}

