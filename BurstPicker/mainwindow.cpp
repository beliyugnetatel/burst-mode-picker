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


void MainWindow::ShowImage(const QString &filePath)
{
    if (ui->graphicsView->scene())
    {
        ui->graphicsView->scene()->deleteLater();
    }

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap(filePath));

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

void MainWindow::on_openFolderbtn_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select Images",
        QDir::homePath(),
        "Images (*.jpg *.jpeg *.png)");

    if (files.isEmpty()) return;

    auto list = ui->listWidget;
    auto graphView = ui->graphicsView;

    for (const QString &file : files)
    {
        QFileInfo fileInfo(file);
        QString fileName = fileInfo.fileName();

        QListWidgetItem *item = new QListWidgetItem(QIcon(file), fileName);
        item->setData(Qt::UserRole, file);
        list->addItem(item);
    }

    if (list->count() > 0)
    {
        list->setCurrentRow(1);

        QString firstFilePath = list->item(0)->data(Qt::UserRole).toString();

        ShowImage(firstFilePath);
    }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString FilePath = item->data(Qt::UserRole).toString();

    ShowImage(FilePath);
}

