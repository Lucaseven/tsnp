#include "MainWindow.h"
#include <QScrollArea>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    createToolBar();
    setupButton();
    createMenus();
}

void MainWindow::setupButton()
{
    m_button = new QPushButton("Pen", m_canvas); // ← parent to canvas, not this
    m_button->setGeometry(10, 10, 150, 40);
    m_button->raise();
    m_button->show();

    connect(m_button, &QPushButton::clicked, this, &MainWindow::handleButton);
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));

    QAction *newAction = new QAction(tr("&New"), this);
    QAction *openAction = new QAction(tr("&Open..."), this);
    QAction *saveAction = new QAction(tr("&Save"), this);
    QAction *exitAction = new QAction(tr("E&xit"), this);
    QAction *undoAction = new QAction(tr("&Undo"), this);
    QAction *redoAction = new QAction(tr("&Redo"), this);
    QAction *cutAction = new QAction(tr("Cut"), this);
    QAction *copyAction = new QAction(tr("&Copy"), this);
    QAction *pasteAction = new QAction(tr("&Paste"), this);

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);

    connect(exitAction, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::createToolBar()
{
    QToolBar* toolBar = addToolBar(tr("Tools"));
    addToolBar(Qt::LeftToolBarArea, toolBar);

    QAction *brushAction = new QAction(tr("Brush"), this);
    QAction *fillAction = new QAction(tr("Fill"), this);
    QAction *shapesAction = new QAction(tr("Shapes"), this);

    toolBar->addAction(brushAction);
    toolBar->addAction(fillAction);
    toolBar->addAction(shapesAction);
}

void MainWindow::setupUI()
{
    setWindowTitle("TSNP - Paint");
    resize(1280, 800);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setAlignment(Qt::AlignCenter);
    scrollArea->setStyleSheet("background-color: #3c3c3c;");

    m_canvas = new CanvasWidget(1920, 1080, this);  // ← create first
    m_canvas->setActiveTool(&m_penTool);             // ← then use it

    scrollArea->setWidget(m_canvas);
    setCentralWidget(scrollArea);

}

void MainWindow::handleButton() {
    // Action to perform when the button is clicked
    m_button->setText("Clicked!");
}