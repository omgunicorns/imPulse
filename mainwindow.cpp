#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <array>
#include <QPixmap>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMultimedia/QSound>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/Images/Facebook-Download-PNG.png");
    ClickableLabel *DO = new ClickableLabel("", ui->noteDO);
    DO->setPixmap(pix.scaled(64, 128, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->type()==QEvent::KeyPress) {
            QKeyEvent* key = static_cast<QKeyEvent*>(event);
            //QMessageBox::information(this, "zag", "text");

            switch (key->key()){
                case Qt::Key_A:
                    QSound::play(":/music/wavs/1.wav");

//                    QMessageBox::information(this, "zag", "text");
                    break;
            }
    }

}

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent)
    :QLabel(parent)
{
    setText(text);
}

ClickableLabel::~ClickableLabel(){}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
//нажатие
}

void MainWindow::on_pushButton_clicked()
{

}
