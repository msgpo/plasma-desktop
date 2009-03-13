/***************************************************************************
 *   Copyright (C) 2009 by Wang Hoi <zealot.hoi@gmail.com>                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/
#ifndef KIM_STATUSBAR_GRAPHICS_H
#define KIM_STATUSBAR_GRAPHICS_H

#include <plasma/applet.h>
#include <plasma/widgets/iconwidget.h>
#include <QGraphicsLinearLayout>
#include <QGraphicsGridLayout>
#include <QGraphicsLayoutItem>
#include <QList>
#include <KIcon>
#include <KDialog>

//#include "kimagenttype.h"
#include "kimpanelagent.h"
#include "kimpanellayout.h"

class PanelAgent;
class KIMStatusBar;

class KIMStatusBarGraphics : public QGraphicsWidget
{
Q_OBJECT
public:
    KIMStatusBarGraphics(PanelAgent *agent=0, QGraphicsItem *parent=0);
    ~KIMStatusBarGraphics();

    /**
     * Returns hints about the geometry of the figure
     * @return Hints about proportionality of the applet
     */
//X      QSizeF sizeHint(Qt::SizeHint which, const QSizeF & constraint = QSizeF()) const;

    inline int iconCount() const
    {
        return m_icons.size();
    }

    bool collapsible() const 
    {
        return m_enableCollapse;
    }
    bool logoVisible() const
    {
        return m_logoVisible;
    }
    void setCollapsible(bool b); 
    void showLogo(bool b);

    QList<QAction *> actions() const;


Q_SIGNALS:
    void collapsed(bool b);
    void iconCountChanged();
    void adjustLocation(int x,int y);

    void triggerProperty(const QString &key);

public Q_SLOTS:
    void updateProperty(const Property &prop);
    void registerProperties(const QList<Property> &props);
    void execDialog(const Property &prop);
    void execMenu(const QList<Property> &props);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected Q_SLOTS:

private Q_SLOTS:
    void changeCollapseStatus();

private:
    KIMPanelLayout *m_layout;
    QList<Plasma::IconWidget *> m_icons;
    Plasma::FrameSvg *m_background;

    bool m_collapsed;
    bool m_enableCollapse;
    bool m_logoVisible;

    QAction *m_collapseAction;
    QAction *m_reloadConfigAction;
    Plasma::IconWidget *m_logoIcon;
    Plasma::IconWidget *m_collapseIcon;

    QList<Property> m_props;
    QMap<QString,Plasma::IconWidget *> m_prop_map;
    QSignalMapper *m_icon_mapper;

    QList<QAction *> m_statusbarActions;

    bool m_empty;

    PanelAgent *m_panel_agent;
};
#endif // KIM_STATUSBAR_GRAPHICS_H
