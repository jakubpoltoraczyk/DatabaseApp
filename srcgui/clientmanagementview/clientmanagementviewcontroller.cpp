#include "clientmanagementviewcontroller.h"

#include "clientmodel.h"

#include <QDebug>

ClientManagementViewController::ClientManagementViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient,
    std::shared_ptr<WindowManager> newWindowManager)
    : dataBaseClient(newDataBaseClient), windowManager(newWindowManager) {}

void ClientManagementViewController::updateView() {
  ClientModel model;
  model.firstName = "Jakub";
  model.lastName = "Poltoraczyk";
  model.pesel = "00262503893";
  model.phoneNumber = "25024133";
  model.mailAdress = "kubafil@onet.pl";
  model.city = "Wroclaw";
  model.postalCode = "63-550";
  model.street = " Plac Grunwaldzki";
  model.houseNumber = "22";

  QVariantList newModels;
  for (int i = 0; i < 25; ++i) {
    newModels.append(QVariant::fromValue(model));
  }

  emit viewChanged(newModels);
}

void ClientManagementViewController::onDeleteButtonReleased(const QString& clientPesel) {
  dataBaseClient->deleteUser(clientPesel.toStdString());

  QVariantList newModels;
  for (int i = 0; i < 25; ++i) {
    newModels.append(QVariant::fromValue(ClientModel()));
  }

  emit viewChanged(newModels);
}

void ClientManagementViewController::onUpdateButtonReleased() {
  windowManager->setClientIdentitiesWindowVisibility(
      true, WindowManager::ClientIdentitiesWindowMode::UPDATE);
}
