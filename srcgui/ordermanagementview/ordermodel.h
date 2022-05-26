#pragma once

#include <QObject>

class OrderModel {
  Q_GADGET
public:
  Q_PROPERTY(QString orderID MEMBER orderID)
  QString orderID;

  Q_PROPERTY(QString pesel MEMBER pesel)
  QString pesel;

  Q_PROPERTY(QString licenseNumber MEMBER licenseNumber)
  QString licenseNumber;

  Q_PROPERTY(QString variantID MEMBER variantID)
  QString variantID;

  Q_PROPERTY(QString orderDate MEMBER orderDate)
  QString orderDate;

  Q_PROPERTY(QString receptionDate MEMBER receptionDate)
  QString receptionDate;

  Q_PROPERTY(QString price MEMBER price)
  QString price;
};
