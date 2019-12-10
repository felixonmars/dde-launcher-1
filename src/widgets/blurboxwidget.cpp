#include "blurboxwidget.h"
#include "src/global_util/calculate_util.h"
#include <QMouseEvent>


DWIDGET_USE_NAMESPACE
BlurBoxWidget::BlurBoxWidget(QWidget *parent)
    : DBlurEffectWidget(parent)
    , m_vLayout(new QVBoxLayout(this))
    , m_maskLayer(new QWidget(this))
    , m_calcUtil(CalculateUtil::instance())
{
    setMaskColor(DBlurEffectWidget::AutoColor);
    setBlendMode(DBlurEffectWidget::InWindowBlend);
    setMaskAlpha(DLauncher::APPHBOX_ALPHA);
    setBlurRectXRadius(DLauncher::APPHBOX_RADIUS);
    setBlurRectYRadius(DLauncher::APPHBOX_RADIUS);
    setFixedWidth(m_calcUtil->getAppBoxSize().width());

    m_maskLayer->setStyleSheet("QWidget{border-radius:40px;background-color:rgba(1, 1, 1, 67)}");

    setLayout(m_vLayout);
    m_vLayout->setSpacing(10);
    m_vLayout->setAlignment(Qt::AlignTop);

    initconnect();
}

void BlurBoxWidget::initconnect()
{

}

void BlurBoxWidget::layoutAddWidget(QWidget *child)
{
    m_vLayout->addWidget(child);
}

void BlurBoxWidget::layoutAddWidget(QWidget *child, int stretch, Qt::Alignment alignment)
{
    m_vLayout->addWidget(child, stretch, alignment);
}

void BlurBoxWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        mousePos = e->pos();
    }
}

void BlurBoxWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton && e->pos() == mousePos) {
        int nNext = 0;
        if (m_calcUtil->getScreenSize().width() / 2 < e->globalX()) {
            nNext = 1;
        } else {
            nNext = -1;
        }
        emit maskClick(getCategory(), nNext);
    }
}

void BlurBoxWidget::setMaskSize(QSize size)
{
    m_maskLayer->move(0, -3);
    m_maskLayer->setFixedSize(size);
    m_maskLayer->raise();
}

void BlurBoxWidget::setMaskVisible(bool visible)
{
    m_maskLayer->setVisible(visible);
}


