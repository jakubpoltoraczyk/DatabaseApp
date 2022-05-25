#pragma once

#include <QObject>

class ClientServiceViewController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString firstName WRITE setFirstName)
  Q_PROPERTY(QString lastName WRITE setLastName)
  Q_PROPERTY(QString pesel WRITE setPesel)
  Q_PROPERTY(QString phoneNumber WRITE setPhoneNumber)
  Q_PROPERTY(QString orderID WRITE setOrderID)
  Q_PROPERTY(QString licenseNumber WRITE setLicenseNumber)
  Q_PROPERTY(QString variantID WRITE setVariantID)
  Q_PROPERTY(QString orderDate WRITE setOrderDate)
  Q_PROPERTY(QString receptionDate WRITE setReceptionDate)
  Q_PROPERTY(QString price WRITE setPrice)
public:
  using QObject::QObject;

public slots:
  /** Called when register button has been just released */
  void onRegisterButtonReleased();

  /** Called when make order button has been just released */
  void onMakeOrderButtonReleased();

signals:
  /** Emiited when order has been accepted */
  void collectDataFromGUI();

private:
  void setFirstName(const QString& newFirstName) { firstName = newFirstName; }
  QString firstName;

  void setLastName(const QString& newLastName) { lastName = newLastName; }
  QString lastName;

  void setPesel(const QString& newPesel) { pesel = newPesel; }
  QString pesel;

  void setPhoneNumber(const QString& newPhoneNumber) { phoneNumber = newPhoneNumber; }
  QString phoneNumber;

  void setOrderID(const QString& newOrderID) { orderID = newOrderID; }
  QString orderID;

  void setLicenseNumber(const QString newLicenseNumber) { licenseNumber = newLicenseNumber; }
  QString licenseNumber;

  void setVariantID(const QString& newVariantID) { variantID = newVariantID; }
  QString variantID;

  void setOrderDate(const QString newOrderDate) { orderDate = newOrderDate; }
  QString orderDate;

  void setReceptionDate(const QString newReceptionDate) { receptionDate = newReceptionDate; }
  QString receptionDate;

  void setPrice(const QString& newPrice) { price = newPrice; }
  QString price;
};
