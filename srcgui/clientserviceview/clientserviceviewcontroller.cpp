#include "clientserviceviewcontroller.h"

#include "../../srcback/models.h"

ClientServiceViewController::ClientServiceViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient,
    std::shared_ptr<WindowManager> newWindowManager)
    : dataBaseClient(newDataBaseClient), windowManager(newWindowManager) {}

void ClientServiceViewController::onRegisterButtonReleased() {
  emit collectDataFromClientIdentitiesComponent();
  windowManager->setClientIdentitiesWindowVisibility(true);
  emit windowManager->completeClientIdentitiesWindowData(firstName, lastName, pesel, phoneNumber);
}

void ClientServiceViewController::onMakeOrderButtonReleased() {
  emit collectDataFromClientIdentitiesComponent();
  emit collectDataFromOrderDatasetComponent();
  auto model = Models::OrderModel{orderID.toStdString(),       pesel.toStdString(),
                                  licenseNumber.toStdString(), variantID.toStdString(),
                                  orderDate.toStdString(),     receptionDate.toStdString(),
                                  price.toStdString()};
  dataBaseClient->createOrder(std::move(model));
}
