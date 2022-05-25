#pragma once

#include "../../srcback/databaseclient/databaseclient.h"

#include <QObject>

#include <memory>

class ClientServiceViewController : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString firstName MEMBER firstName)
  Q_PROPERTY(QString lastName MEMBER lastName)
  Q_PROPERTY(QString pesel MEMBER pesel)
  Q_PROPERTY(QString phoneNumber MEMBER phoneNumber)
  Q_PROPERTY(QString orderID MEMBER orderID)
  Q_PROPERTY(QString licenseNumber MEMBER licenseNumber)
  Q_PROPERTY(QString variantID MEMBER variantID)
  Q_PROPERTY(QString orderDate MEMBER orderDate)
  Q_PROPERTY(QString receptionDate MEMBER receptionDate)
  Q_PROPERTY(QString price MEMBER price)
public:
  /**
   * @brief Create a new instance of client service view controller
   * @param newDataBaseClient DataBaseClient object to communicate with database
   */
  ClientServiceViewController(std::shared_ptr<DataBaseClient> newDataBaseClient);

public slots:
  /** Called when register button has been just released */
  void onRegisterButtonReleased();

  /** Called when make order button has been just released */
  void onMakeOrderButtonReleased();

signals:
  /** Emiited when order has been accepted */
  void collectDataFromGUI();

private:
  QString firstName;
  QString lastName;
  QString pesel;
  QString phoneNumber;
  QString orderID;
  QString licenseNumber;
  QString variantID;
  QString orderDate;
  QString receptionDate;
  QString price;

  std::shared_ptr<DataBaseClient> dataBaseClient;
};
