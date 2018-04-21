#include "keyhandler.cpp"
#include <vector>
void notePressed(QLabel *label, QString colcode)
{
    label->setStyleSheet("QLabel { background-color: "+colcode+";  margin:5px; border-radius:5px; border: 1px solid grey; }");

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/Images/Facebook-Download-PNG.png");
    int x = 20, y = 260;

    for(int i = 0; i < 10; ++i){
        QLabel *label = new QLabel("", this);
        label->setGeometry(x, y, 64, 128);
        x += 64;
        label->setStyleSheet("background-color: white;  margin:5px; border-radius:5px; border: 1px solid grey;");
        label->show();
        notes.push_back(label);
    }
    x = 20 + 32 + 8, y = 260;
    for(int i = 0; i < 7; ++i)
    {
        QLabel *label = new QLabel("", this);
        label->setGeometry(x, y, 64 - 16, 64 + 16);
        x += 64;
        label->setStyleSheet("background-color: black;  margin:5px; border-radius:5px; border: 1px solid grey;");
        label->show();
        semiNotes.push_back(label);
        if(i == 1 || i == 4)
            x+=64;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        KeyHandler(event);
        QColor color = Qt::blue;
        QVariant variant = color;
        QString blueCol = variant.toString();
        color = Qt::green;
        variant = color;
        QString greenCol = variant.toString();

        switch (event->key()){
            case Qt::Key_A: notePressed(this->notes[0], blueCol); break;
            case Qt::Key_S: notePressed(this->notes[1], blueCol); break;
            case Qt::Key_D: notePressed(this->notes[2], blueCol); break;
            case Qt::Key_F: notePressed(this->notes[3], blueCol); break;
            case Qt::Key_G: notePressed(this->notes[4], blueCol); break;
            case Qt::Key_H: notePressed(this->notes[5], blueCol); break;
            case Qt::Key_J: notePressed(this->notes[6], blueCol); break;
            case Qt::Key_K: notePressed(this->notes[7], blueCol); break;
            case Qt::Key_L: notePressed(this->notes[8], blueCol); break;
            case Qt::Key_Semicolon: notePressed(this->notes[9], blueCol); break;

            case Qt::Key_W:notePressed(this->semiNotes[0], greenCol); break;
            case Qt::Key_E:notePressed(this->semiNotes[1], greenCol); break;
            case Qt::Key_T:notePressed(this->semiNotes[2], greenCol); break;
            case Qt::Key_Y:notePressed(this->semiNotes[3], greenCol); break;
            case Qt::Key_U:notePressed(this->semiNotes[4], greenCol); break;
            case Qt::Key_O:notePressed(this->semiNotes[5], greenCol); break;
            case Qt::Key_P:notePressed(this->semiNotes[6], greenCol); break;
        }
    }


}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if (event->type() == QEvent::KeyRelease){
        QColor color = Qt::white;
        QVariant variant = color;
        QString whiteCol = variant.toString();
        QString blackCol = "#000000";
        switch (event->key()){
            case Qt::Key_A: notePressed(this->notes[0], whiteCol); break;
            case Qt::Key_S: notePressed(this->notes[1], whiteCol); break;
            case Qt::Key_D: notePressed(this->notes[2], whiteCol); break;
            case Qt::Key_F: notePressed(this->notes[3], whiteCol); break;
            case Qt::Key_G: notePressed(this->notes[4], whiteCol); break;
            case Qt::Key_H: notePressed(this->notes[5], whiteCol); break;
            case Qt::Key_J: notePressed(this->notes[6], whiteCol); break;
            case Qt::Key_K: notePressed(this->notes[7], whiteCol); break;
            case Qt::Key_L: notePressed(this->notes[8], whiteCol); break;
            case Qt::Key_Semicolon: notePressed(this->notes[9], whiteCol); break;//w e t y u o p

            case Qt::Key_W:notePressed(this->semiNotes[0], blackCol); break;
            case Qt::Key_E:notePressed(this->semiNotes[1], blackCol); break;
            case Qt::Key_T:notePressed(this->semiNotes[2], blackCol); break;
            case Qt::Key_Y:notePressed(this->semiNotes[3], blackCol); break;
            case Qt::Key_U:notePressed(this->semiNotes[4], blackCol); break;
            case Qt::Key_O:notePressed(this->semiNotes[5], blackCol); break;
            case Qt::Key_P:notePressed(this->semiNotes[6], blackCol); break;
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
