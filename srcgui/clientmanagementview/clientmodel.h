#pragma once

#include <QObject>

class ClientModel {
  Q_GADGET
public:
  Q_PROPERTY(QString firstName MEMBER firstName)
  QString firstName;

  Q_PROPERTY(QString lastName MEMBER lastName)
  QString lastName;

  Q_PROPERTY(QString pesel MEMBER pesel)
  QString pesel;

  Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
  QString phoneNumber;

  Q_PROPERTY(QString mailAdress MEMBER mailAdress)
  QString mailAdress;

  Q_PROPERTY(QString postalCode MEMBER postalCode)
  QString postalCode;

  Q_PROPERTY(QString city MEMBER city)
  QString city;

  Q_PROPERTY(QString street MEMBER street)
  QString street;

  Q_PROPERTY(QString houseNumber MEMBER houseNumber)
  QString houseNumber;
};
