#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
#include <QLabel>
#include <QSpacerItem>
#include <QPropertyAnimation>

#include <dimagebutton.h>

DWIDGET_USE_NAMESPACE

class SearchLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    enum DisplayMode
    {
        EditMode,
        EchoMode,
    };

public:
    explicit SearchLineEdit(QWidget *parent = nullptr);

public slots:
    void normalMode();

private slots:
    void editMode();

protected:
    bool event(QEvent *e);

private:
    DisplayMode m_mode = EchoMode;
    DImageButton *m_icon;
    QLabel *m_placeholderText;
    QWidget *m_floatWidget;
    QPropertyAnimation *m_floatAni;
};

#endif // SEARCHLINEEDIT_H
