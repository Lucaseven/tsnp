#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ScribbleArea;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
}
