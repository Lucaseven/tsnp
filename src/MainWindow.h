#pragma once

#include <QMainWindow>
#include <QPushButton>
#include "canvas/CanvasWidget.h"
#include "tools/PenTool.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void handleButton();

private:
    CanvasWidget* m_canvas;
    QPushButton *m_button;
    PenTool       m_penTool;
    void setupUI();
    void setupButton();
    void createMenus();
    void createToolBar();
};