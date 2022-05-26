#include "clientmanagementviewcontroller.h"

#include "clientmodel.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

ClientManagementViewController::ClientManagementViewController(
    std::shared_ptr<DataBaseClient> newDataBaseClient,
    std::shared_ptr<WindowManager> newWindowManager)
    : dataBaseClient(newDataBaseClient), windowManager(newWindowManager) {}

void ClientManagementViewController::updateView() {
  auto doc = dataBaseClient->readClients();

  auto jsonArray = doc.array();

  clientModels.clear();
  clientModels.reserve(jsonArray.size());

  for (QJsonValueRef jsonValueRef : jsonArray) {
    auto jsonObject = jsonValueRef.toObject();
    ClientModel model;
    model.firstName = jsonObject["firstName"].toString();
    model.lastName = jsonObject["lastName"].toString();
    model.pesel = jsonObject["pesel"].toString();
    model.phoneNumber = jsonObject["phoneNumber"].toString();
    model.mailAdress = jsonObject["mailAdress"].toString();
    model.city = jsonObject["city"].toString();
    model.postalCode = jsonObject["postalCode"].toString();
    model.street = jsonObject["street"].toString();
    model.houseNumber = jsonObject["houseNumber"].toString();
    clientModels.push_back(QVariant::fromValue(model));
  }

  emit viewChanged(clientModels);
}

void ClientManagementViewController::onDeleteButtonReleased(const QString& clientPesel) {
  dataBaseClient->deleteClient(clientPesel.toStdString());
  updateView();
}

void ClientManagementViewController::onUpdateButtonReleased(int modelIndex) {
  windowManager->setClientIdentitiesWindowVisibility(
      true, WindowManager::ClientIdentitiesWindowMode::UPDATE);

  auto model = clientModels.at(modelIndex).value<ClientModel>();
  windowManager->completeClientIdentitiesWindowData(
      {model.firstName, model.lastName, model.pesel, model.phoneNumber, model.mailAdress,
       model.city, model.postalCode, model.street, model.houseNumber});
}
