#ifndef ECONTAINER_H
#define ECONTAINER_H
/*
 * Programmer Aleksey Osipov
 * email: aliks-os@yandex.ru
 */
#include <QWidget>
#include <QMouseEvent>
#include <QtGui>
#include <QVBoxLayout>
#include <QMenu>



class EContainer : public QWidget {
    Q_OBJECT

public:
    EContainer(QWidget *parent, QPoint p, QWidget *cWidget = 0);
    ~EContainer();

    enum modes{
        NONE = 0,
        MOVE = 1,
        RESIZETL = 2,
        RESIZET = 3,
        RESIZETR = 4,
        RESIZER = 5,
        RESIZEBR = 6,
        RESIZEB = 7,
        RESIZEBL = 8,
        RESIZEL = 9
    };

    QWidget *childWidget;
    QMenu *menu;
    void setChildWidget(QWidget *cWidget);

    void setModeEnable(modes var){m_modeEnable = var;}
    void setMoveEnable(bool var){m_moveEnable = var;}
protected:
    int mode;
    QPoint position;
    QVBoxLayout* vLayout;
    void setCursorShape(const QPoint &e_pos);
    bool eventFilter(QObject *obj, QEvent *evt);
    void keyPressEvent(QKeyEvent*);
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent *);
    bool m_infocus;
    bool m_showMenu;
    bool m_isEditing;
    void popupShow(const QPoint &pt);
    QWidget *clone();

signals:
    void inFocus(bool mode);
    void outFocus(bool mode);
    void newGeometry(QRect rect);

private:
    modes m_modeEnable = NONE;
    bool m_moveEnable = true;
};

#endif // TCONTAINER_H
