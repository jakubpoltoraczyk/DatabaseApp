#include "clientserviceviewcontroller.h"

#include "../../srcback/models.h"

ClientServiceViewController::ClientServiceViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient) {}

void ClientServiceViewController::onRegisterButtonReleased() {}

void ClientServiceViewController::onMakeOrderButtonReleased() {
  emit collectDataFromGUI();
  auto model = Models::OrderModel{orderID.toStdString(),       pesel.toStdString(),
                                  licenseNumber.toStdString(), variantID.toStdString(),
                                  orderDate.toStdString(),     receptionDate.toStdString(),
                                  price.toStdString()};
  dataBaseClient->createOrder(std::move(model));
}
