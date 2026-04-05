#include "CanvasWidget.h"

#include <QPainter>
#include <QPaintEvent>

CanvasWidget::CanvasWidget(int width, int height, QWidget *parent)
    : QWidget(parent)
    // ARGB32_Premultiplied is the fastest format for QPainter operations.
    // We'll use this throughout the project for all layer buffers.
    , m_canvas(width, height, QImage::Format_ARGB32_Premultiplied)
{
    initCanvas();

    // Fix the widget size to match the canvas resolution.
    // The scroll area in MainWindow handles overflow.
    setFixedSize(width, height);
}

void CanvasWidget::initCanvas()
{
    clear(Qt::white);
}

void CanvasWidget::clear(const QColor &color)
{
    m_canvas.fill(color);
    update(); // schedule a repaint
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // Draw the canvas image onto the widget surface.
    // As we add zoom later, we'll apply a transform here.
    painter.drawImage(0, 0, m_canvas);
}
