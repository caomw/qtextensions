/*ckwg +5
 * Copyright 2015 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef __qtThrobber_h
#define __qtThrobber_h

#include <QWidget>

#include "../core/qtGlobal.h"

class qtThrobberPrivate;

class QTE_EXPORT qtThrobber : public QWidget
{
  Q_OBJECT

  Q_PROPERTY(bool active READ isActive WRITE setActive)
  Q_PROPERTY(int maxThrobberSize READ maxThrobberSize WRITE setMaxThrobberSize)

public:
  qtThrobber(QWidget* parent = 0);
  virtual ~qtThrobber();

  QSize minimumSizeHint() const;
  bool isActive() const;
  int maxThrobberSize() const;

signals:
  void toggled(bool);

public slots:
  void setActive(bool);
  void setMaxThrobberSize(int);

protected slots:
  void step();

protected:
  QTE_DECLARE_PRIVATE_RPTR(qtThrobber)

  void paintEvent(QPaintEvent*);

private:
  QTE_DECLARE_PRIVATE(qtThrobber)
  QTE_DISABLE_COPY(qtThrobber)
};

#endif
