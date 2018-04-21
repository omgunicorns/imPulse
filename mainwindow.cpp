#include "keyhandler.cpp"
#include <vector>

#define DEFAULT_W 64
#define DEFAULT_H 128
#define DEFAULT_SCALE 0.25
void notePressed(QLabel *label, QString colcode)
{
    label->setStyleSheet("QLabel { background-color: "+colcode+";  margin:5px; border-radius:5px; border: 1px solid grey; }");

}

QLabel* newNote(MainWindow *parent, int x, int y, bool isDies = false)
{
    QLabel *label = new QLabel("", parent);
    if(isDies)
    {
        label->setGeometry(x, y, DEFAULT_W * (1 - DEFAULT_SCALE), (DEFAULT_H / 2) * (1 + DEFAULT_SCALE));
        label->setStyleSheet("background-color: black;  margin:5px; border-radius:5px; border: 1px solid grey;");
    }
    else
    {
        label->setGeometry(x, y, DEFAULT_W, DEFAULT_H);
        label->setStyleSheet("background-color: white;  margin:5px; border-radius:5px; border: 1px solid grey;");
    }
    label->show();
    return label;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/res/Images/Facebook-Download-PNG.png");
    int x = 20, y = 260;

    for(int i = 0; i < 10; ++i){
        notes.push_back(newNote(this, x, y));
        x += 64;
    }
    x = 20 + 32 + 8, y = 260;
    for(int i = 0; i < 7; ++i)
    {
        semiNotes.push_back(newNote(this, x, y, true));
        x += 64;
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
