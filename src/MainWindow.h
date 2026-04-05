#pragma once

#include <QMainWindow>
#include "canvas/CanvasWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    CanvasWidget *m_canvas;

    void setupUI();
};
