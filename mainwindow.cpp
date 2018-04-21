#include "keyhandler.cpp"


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
        KeyHandler(event);
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
