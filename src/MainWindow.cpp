#include "MainWindow.h"

#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{
    setWindowTitle("TSMP - Paint");
    resize(1280, 800);

    // Wrap the canvas in a scroll area so it can be
    // larger than the window without clipping
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setStyleSheet("background-color: #3c3c3c;");

    m_canvas = new CanvasWidget(1920, 1080, this);

    scrollArea->setWidget(m_canvas);
    setCentralWidget(scrollArea);
}
