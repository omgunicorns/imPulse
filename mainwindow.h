#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtMultimedia/QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

class ClickableLabel : public QLabel
{
Q_OBJECT
public:
    explicit ClickableLabel(const QString& text="", QWidget* parent=0);
    ~ClickableLabel();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
};

class note
{

public:
    explicit note();
    ~note();

    void play();

private:
    ClickableLabel *cLabel = nullptr;
    QString sound;

};


#endif // MAINWINDOW_H
