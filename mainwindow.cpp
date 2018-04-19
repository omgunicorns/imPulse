#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMultimedia/QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/Images/Facebook-Download-PNG.png");
    ClickableLabel *c_label = new ClickableLabel("", ui->label);
    int w = c_label->width();
    int h = c_label->height();
    c_label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
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
                    QSound::play("/Users/petr/CProject/sounds/wav/1.wav");
                    break;
                case Qt::Key_W:
                    QSound::play("/Users/petr/CProject/sounds/wav/2.wav");
                    break;
                case Qt::Key_S:
                    QSound::play("/Users/petr/CProject/sounds/wav/3.wav");
                    break;
                case Qt::Key_E:
                    QSound::play("/Users/petr/CProject/sounds/wav/4.wav");
                    break;
                case Qt::Key_D:
                    QSound::play("/Users/petr/CProject/sounds/wav/5.wav");
                    break;
                case Qt::Key_F:
                    QSound::play("/Users/petr/CProject/sounds/wav/6.wav");
                    break;
                case Qt::Key_T:
                    QSound::play("/Users/petr/CProject/sounds/wav/7.wav");
                    break;
                case Qt::Key_G:
                    QSound::play("/Users/petr/CProject/sounds/wav/8.wav");
                    break;
                case Qt::Key_Y:
                    QSound::play("/Users/petr/CProject/sounds/wav/9.wav");
                    break;
                case Qt::Key_H:
                    QSound::play("/Users/petr/CProject/sounds/wav/10.wav");
                    break;
                case Qt::Key_U:
                    QSound::play("/Users/petr/CProject/sounds/wav/11.wav");
                    break;
                case Qt::Key_J:
                    QSound::play("/Users/petr/CProject/sounds/wav/12.wav");
                    break;
                case Qt::Key_K:
                    QSound::play("/Users/petr/CProject/sounds/wav/13.wav");
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
