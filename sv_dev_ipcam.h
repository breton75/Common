/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia. For licensing terms and
** conditions see http://qt.digia.com/licensing. For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights. These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef SVDEV_IPCAM_H
#define SVDEV_IPCAM_H

#include "log.h"
#include "sv_serverclient.h"
#include "sv_ffmpeg.h"

#include "tthread.h"

#include <QtWidgets>
#include <QRectF>
#include <QColor>
#include <QTcpSocket>
#include <QHostAddress>
#include <QWidget>
#include <QMap>
#include <QColor>
#include <QGraphicsItem>
#include <QString>

class QObject;

class SvDev_IPCam : public QGraphicsItem, public QObject
{
public:
    SvDev_IPCam(QWidget* parent = 0,
                const QColor &brushColor = QColor(0x4A8832),
                const QColor &penColor = QColor(Qt::blue),
                int x = 0,
                int y = 0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

    QWidget* parent;
    int id;
    QString name;
    QString ip = "";
    quint16 service_port = 0;
    quint16 data_port = 0;
    QString link_to_stream = "";
    int posX, posY, posZ;
    
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;

private:
    int x;
    int y;
    QColor brushColor;
    QColor penColor;
    QVector<QPointF> stuff;
};

#endif // SVDEV_IPCAM_H
