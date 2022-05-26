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

void ClientManagementViewController::onUpdateButtonReleased(const QStringList& clientData) {
  Models::UserModel model{clientData.at(0).toStdString(), clientData.at(1).toStdString(),
                          clientData.at(2).toStdString(), clientData.at(3).toStdString(),
                          clientData.at(4).toStdString(), clientData.at(5).toStdString(),
                          clientData.at(6).toStdString(), clientData.at(7).toStdString(),
                          clientData.at(8).toStdString()};

  dataBaseClient->updateUser(std::move(model));

  QVariantList newModels;
  for (int i = 0; i < 25; ++i) {
    newModels.append(QVariant::fromValue(ClientModel()));
  }

  emit viewChanged(newModels);
}
