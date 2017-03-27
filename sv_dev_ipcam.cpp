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

#include "sv_dev_ipcam.h"

using namespace log_ns;

SvFFMpegWidget* ffvideo;

SvDev_IPCam::SvDev_IPCam(QWidget *parent,
                         const QColor &brushColor,
                         const QColor &penColor,
                         int x,
                         int y)
{
  this->parent = parent;  
  this->x = x;
  this->y = y;
  this->brushColor = brushColor;
  this->penColor = penColor;
  
    setZValue((x + y) % 2);

    setFlags(ItemIsSelectable | ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF SvDev_IPCam::boundingRect() const
{
    return QRectF(0, 0, 35, 35);
}

QPainterPath SvDev_IPCam::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 82, 42);
    return path;
}

void SvDev_IPCam::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    static const QPointF points[4] = {
      QPointF(17.0, 10.0),
      QPointF(25.0, 05.0),
      QPointF(25.0, 25.0),
      QPointF(17.0, 20.0)
    };

    QRectF rectangle(1.0, 10.0, 15.0, 10.0);
    QRectF rectangle2(8.0, 12.0, 5.0, 4.0);
    
    int startAngle = 290 * 16;
    int spanAngle = -180 * 16;
    
    QColor fillColor = (option->state & QStyle::State_Selected) ? brushColor.dark(150) : brushColor;
    if (option->state & QStyle::State_MouseOver)
        fillColor = fillColor.light(125);

    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
//    if (lod < 0.2) {
//        if (lod < 0.125) {
//            painter->fillRect(QRectF(0, 0, 110, 70), fillColor);
//            return;
//        }

//        QBrush b = painter->brush();
//        painter->setBrush(fillColor);
//        painter->drawRect(13, 13, 97, 57);
//        painter->setBrush(b);
//        return;
//    }

//    QPen oldPen = painter->pen();
//    QPen pen = oldPen;
//    int width = 0;
//    if (option->state & QStyle::State_Selected)
//        width += 2;

//    pen.setWidth(width);

    painter->setPen(QPen(penColor, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

//    QBrush b = painter->brush();
    painter->setBrush(QBrush(fillColor.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawPolygon(points, 4);
    painter->drawRoundedRect(rectangle, 0, 1);
    painter->drawRoundedRect(rectangle2, 1, 1);
//    painter->drawEllipse(QPoint(14, 30), 3, 3);
//    painter->drawPie(rectangle, startAngle, spanAngle);

    
    
    
    return;
    
    if (lod >= 1) {
        painter->setPen(QPen(Qt::gray, 1));
        painter->drawLine(15, 54, 94, 54);
        painter->drawLine(94, 53, 94, 15);
        painter->setPen(QPen(Qt::black, 0));
    }

    // Draw text
    if (lod >= 2) {
        QFont font("Times", 10);
        font.setStyleStrategy(QFont::ForceOutline);
        painter->setFont(font);
        painter->save();
        painter->scale(0.1, 0.1);
        painter->drawText(170, 180, QString("Model: VSC-2000 (Very Small Chip) at %1x%2").arg(x).arg(y));
        painter->drawText(170, 200, QString("Serial number: DLWR-WEER-123L-ZZ33-SDSJ"));
        painter->drawText(170, 220, QString("Manufacturer: Chip Manufacturer"));
        painter->restore();
    }

    // Draw lines
    QVarLengthArray<QLineF, 36> lines;
    if (lod >= 0.5) {
        for (int i = 0; i <= 10; i += (lod > 0.5 ? 1 : 2)) {
            lines.append(QLineF(18 + 7 * i, 13, 18 + 7 * i, 5));
            lines.append(QLineF(18 + 7 * i, 54, 18 + 7 * i, 62));
        }
        for (int i = 0; i <= 6; i += (lod > 0.5 ? 1 : 2)) {
            lines.append(QLineF(5, 18 + i * 5, 13, 18 + i * 5));
            lines.append(QLineF(94, 18 + i * 5, 102, 18 + i * 5));
        }
    }
    if (lod >= 0.4) {
        const QLineF lineData[] = {
            QLineF(25, 35, 35, 35),
            QLineF(35, 30, 35, 40),
            QLineF(35, 30, 45, 35),
            QLineF(35, 40, 45, 35),
            QLineF(45, 30, 45, 40),
            QLineF(45, 35, 55, 35)
        };
        lines.append(lineData, 6);
    }
    painter->drawLines(lines.data(), lines.size());

    // Draw red ink
    if (stuff.size() > 1) {
        QPen p = painter->pen();
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter->setBrush(Qt::NoBrush);
        QPainterPath path;
        path.moveTo(stuff.first());
        for (int i = 1; i < stuff.size(); ++i)
            path.lineTo(stuff.at(i));
        painter->drawPath(path);
        painter->setPen(p);
    }
}

void SvDev_IPCam::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void SvDev_IPCam::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void SvDev_IPCam::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}

void SvDev_IPCam::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
  
  if(ffvideo) ffvideo->~SvFFMpegWidget();
  ffvideo = new SvFFMpegWidget(QString(this->link_to_stream),
                              320,
                              240,
                              this->posX + 10,
                              this->posY + 10,
                              this->name);
  
  if(parent) ffvideo->setParent(this->parent);
  ffvideo->show();
    
  log_ns::log(m_Attention, "CreateWidget OK");
  
/******************************************************************/  
//  if(rtsp) rtsp->~SvRTSPWidget();
//    log_ns::log(m_Attention, "111 ~SvRTSPWidget OK");
//  rtsp = new SvRTSPWidget();
//  log_ns::log(m_Attention, "222 ~SvRTSPWidget OK");
//  rtsp->CreateWidget(/*ui->widget,*/
//                           QString(this->link_to_stream),/*.toStdString().c_str()*/
//                           QString(this->name),/*.toStdString().c_str()*/
//  //                        QString("rtsp://217.17.220.110/axis-media/media.amp"),/*"rtsp://169.254.1.90/axis-media/media.amp"),*//*.toStdString().c_str()*/
//  //                        QString("217.17.220.110"),/*.toStdString().c_str()*/
//                          this->posX + 60,
//                          this->posY + 170,
//                          4,
//                          this->id);
//  log_ns::log(m_Attention, "CreateWidget OK");
  
 /***************************************************************/ 

      
}

