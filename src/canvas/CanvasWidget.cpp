// src/canvas/CanvasWidget.cpp
#include "CanvasWidget.h"
#include <QPainter>
#include <QMouseEvent>

CanvasWidget::CanvasWidget(int width, int height, QWidget* parent)
    : QWidget(parent)
    , m_canvas(width, height, QImage::Format_ARGB32_Premultiplied)
{
    initCanvas();
    setFixedSize(width, height);

    // Required for Qt to send mouseMoveEvent while button is held
    setMouseTracking(false);
}

void CanvasWidget::initCanvas()
{
    clear(Qt::white);
}

void CanvasWidget::clear(const QColor& color)
{
    m_canvas.fill(color);
    update();
}

// Converts a QMouseEvent into your own InputEvent struct.
// This is the only place in the project that touches QMouseEvent directly.
InputEvent CanvasWidget::buildInputEvent(QMouseEvent* event) const
{
    InputEvent ev;
    ev.pos      = event->position();  // current position
    ev.lastPos  = m_lastPos;          // previous position
    ev.pressure = 1.0f;               // mouse always full pressure
    return ev;
}

void CanvasWidget::mousePressEvent(QMouseEvent* event)
{
    if (!m_activeTool) return;
    if (event->button() != Qt::LeftButton) return;

    m_lastPos = event->position();    // initialise before building event
    InputEvent ev = buildInputEvent(event);
    m_activeTool->onPress(m_canvas, ev, m_brush);
    update(); // schedule repaint
}

void CanvasWidget::mouseMoveEvent(QMouseEvent* event)
{
    if (!m_activeTool) return;
    if (!(event->buttons() & Qt::LeftButton)) return;

    InputEvent ev = buildInputEvent(event);
    m_activeTool->onDrag(m_canvas, ev, m_brush);
    m_lastPos = event->position();    // update after building event
    update();
}

void CanvasWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (!m_activeTool) return;
    if (event->button() != Qt::LeftButton) return;

    InputEvent ev = buildInputEvent(event);
    m_activeTool->onRelease(m_canvas, ev, m_brush);
    update();
}

void CanvasWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawImage(0, 0, m_canvas);
}