#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->showMaximized();

}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionLoad_Image_triggered()
{
  QString fileName = QFileDialog::getOpenFileName(this,
                                                  tr("Open Image"), "//home", tr("Image Files (*.dng)"));

  ui->label_2->setText(fileName);
  auto pimg=process_image(fileName.toStdString().c_str());
  QImage qimg(pimg.imdata,pimg.imwidth,pimg.imheight,QImage::Format_BGR888);
  QImage rimg =qimg.scaled(pimg.imwidth/4, pimg.imheight/4);
  QPixmap pixmap = QPixmap::fromImage(rimg);
  ui->imlabel->setPixmap(pixmap);
  ui->imlabel->setFixedSize(pixmap.size());




}





