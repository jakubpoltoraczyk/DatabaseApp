#pragma once

#include "../../srcback/databaseclient/databaseclient.h"

#include <QObject>

#include <memory>

class OrderManagementViewController : public QObject {
  Q_OBJECT
public:
  OrderManagementViewController(std::shared_ptr<DataBaseClient> newDataBaseClient);

  void updateView();

public slots:
  void onDeleteButtonReleased(const QString& deleteOrderID);

  void onCompleteButtonReleased(const QString& completeOrderID);

signals:
  void viewChanged(QVariantList newModels);

private:
  std::shared_ptr<DataBaseClient> dataBaseClient;
};
