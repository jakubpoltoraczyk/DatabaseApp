#include "clientserviceviewcontroller.h"

#include "../../srcback/models.h"

#include <utility>

ClientServiceViewController::ClientServiceViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient,
    std::shared_ptr<WindowManager> newWindowManager,
    std::shared_ptr<CustomMessageDialogController> newCustomMessageDialogController)
    : dataBaseClient(newDataBaseClient), windowManager(newWindowManager),
      customMessageDialogController(newCustomMessageDialogController) {}

void ClientServiceViewController::onRegisterButtonReleased() {
  emit collectDataFromClientIdentitiesComponent();

  if (!isDataIdentitiesValid()) {
    customMessageDialogController->showMessageDialog("Invalid data",
                                                     "You've entered incorrect client data!");
    return;
  }

  windowManager->setClientIdentitiesWindowVisibility(true);
  emit windowManager->completeClientIdentitiesWindowData(
      {firstName, lastName, pesel, phoneNumber, "", "", "", "", ""});
}

void ClientServiceViewController::onMakeOrderButtonReleased() {
  emit collectDataFromClientIdentitiesComponent();
  emit collectDataFromOrderDatasetComponent();

  if (!isDataIdentitiesValid() || !isOrderDatasetValid()) {
    customMessageDialogController->showMessageDialog(
        "Invalid data", "You've entered incorrect client or order data");
    return;
  }

  auto model = Models::OrderModel{orderID.toStdString(),       pesel.toStdString(),
                                  licenseNumber.toStdString(), variantID.toStdString(),
                                  orderDate.toStdString(),     receptionDate.toStdString(),
                                  price.toStdString()};
  dataBaseClient->createOrder(std::move(model));
}

bool ClientServiceViewController::isDataIdentitiesValid() {
  if (pesel.size() == 11 && firstName.size() > 0 && lastName.size() > 0 &&
      phoneNumber.size() == 9) {
    return true;
  }
  return false;
}

bool ClientServiceViewController::isOrderDatasetValid() {
  if (orderID.size() != 0 && licenseNumber.size() == 7 && variantID.size() != 0 &&
      orderDate.size() != 0 && receptionDate.size() != 0 && price.size() != 0) {
    return true;
  }
  return false;
}
