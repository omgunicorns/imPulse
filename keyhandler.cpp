#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMultimedia/QSound>

#include "etgenerator.cpp"

void KeyHandler(QKeyEvent* event){
    QKeyEvent* e = static_cast<QKeyEvent*>(event);

    double vol = 0.1;

    // ноты по частотам: https://pages.mtu.edu/~suits/notefreqs.html

    switch (e->key()){

       case Qt::Key_A: ETGen(0.2, 130.81, vol); break;
       case Qt::Key_W: ETGen(0.2, 138.59, vol); break;
       case Qt::Key_S: ETGen(0.2, 146.83, vol); break;
       case Qt::Key_E: ETGen(0.2, 155.56, vol); break;
       case Qt::Key_D: ETGen(0.2, 164.81, vol); break;
       case Qt::Key_F: ETGen(0.2, 174.61, vol); break;
       case Qt::Key_T: ETGen(0.2, 185.00, vol); break;
       case Qt::Key_G: ETGen(0.2, 196.00, vol); break;
       case Qt::Key_Y: ETGen(0.2, 207.65, vol); break;
       case Qt::Key_H: ETGen(0.2, 220.00, vol); break;
       case Qt::Key_U: ETGen(0.2, 233.08, vol); break;
       case Qt::Key_J: ETGen(0.2, 246.94, vol); break;
       case Qt::Key_K: ETGen(0.2, 261.63, vol); break;
       case Qt::Key_O: ETGen(0.2, 277.18, vol); break;
       case Qt::Key_L: ETGen(0.2, 293.66, vol); break;
       case Qt::Key_P: ETGen(0.2, 311.13, vol); break;
       case Qt::Key_Semicolon: ETGen(0.2, 329.63, vol); break;

    }
}
