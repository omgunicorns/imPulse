#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtMultimedia/QSound>

#include "ETGenerator.cpp"

#define GEN ETGen
#define GEN CTGen

void KeyHandler(QKeyEvent* event){
    QKeyEvent* e = static_cast<QKeyEvent*>(event);

    double vol = 0.1;
    double dur = 0.3;

    // ноты по частотам: https://pages.mtu.edu/~suits/notefreqs.html

    switch (e->key()){

       case Qt::Key_A: GEN(dur, 130.81, vol); break;
       case Qt::Key_W: GEN(dur, 138.59, vol); break;
       case Qt::Key_S: GEN(dur, 146.83, vol); break;
       case Qt::Key_E: GEN(dur, 155.56, vol); break;
       case Qt::Key_D: GEN(dur, 164.81, vol); break;
       case Qt::Key_F: GEN(dur, 174.61, vol); break;
       case Qt::Key_T: GEN(dur, 185.00, vol); break;
       case Qt::Key_G: GEN(dur, 196.00, vol); break;
       case Qt::Key_Y: GEN(dur, 207.65, vol); break;
       case Qt::Key_H: GEN(dur, 220.00, vol); break;
       case Qt::Key_U: GEN(dur, 233.08, vol); break;
       case Qt::Key_J: GEN(dur, 246.94, vol); break;
       case Qt::Key_K: GEN(dur, 261.63, vol); break;
       case Qt::Key_O: GEN(dur, 277.18, vol); break;
       case Qt::Key_L: GEN(dur, 293.66, vol); break;
       case Qt::Key_P: GEN(dur, 311.13, vol); break;
       case Qt::Key_Semicolon: GEN(dur, 329.63, vol); break;

    }
}
