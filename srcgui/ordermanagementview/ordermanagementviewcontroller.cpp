#include "ordermanagementviewcontroller.h"

#include "ordermodel.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

OrderManagementViewController::OrderManagementViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient) {}

void OrderManagementViewController::updateView() {
  auto doc = dataBaseClient->readOrders();

  auto jsonArray = doc.array();

  QVariantList orderModels;
  orderModels.reserve(jsonArray.size());

  for (QJsonValueRef jsonValueRef : jsonArray) {
    auto jsonObject = jsonValueRef.toObject();
    OrderModel model;
    model.orderID = jsonObject["orderID"].toString();
    model.pesel = jsonObject["pesel"].toString();
    model.licenseNumber = jsonObject["licenseNumber"].toString();
    model.variantID = jsonObject["variantID"].toString();
    model.orderDate = jsonObject["orderDate"].toString();
    model.receptionDate = jsonObject["receptionDate"].toString();
    model.price = jsonObject["price"].toString();
    orderModels.push_back(QVariant::fromValue(model));
  }

  emit viewChanged(orderModels);
}

void OrderManagementViewController::onDeleteButtonReleased(const QString& deleteOrderID) {
  dataBaseClient->deleteOrder(deleteOrderID.toStdString());
  updateView();
}

void OrderManagementViewController::onCompleteButtonReleased(const QString& completeOrderID) {
  dataBaseClient->completeOrder(completeOrderID.toStdString());
  updateView();
}
