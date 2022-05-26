#include "windowmanager.h"

#include <QDebug>

WindowManager::WindowManager(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient) {}

void WindowManager::onRegisterUserConfirmed(const QStringList& userData) {
  emit setClientIdentitiesWindowVisibility(false, clientIdentitiesWindowMode);
  auto model = Models::UserModel{
      userData.at(0).toStdString(), userData.at(1).toStdString(), userData.at(2).toStdString(),
      userData.at(3).toStdString(), userData.at(4).toStdString(), userData.at(5).toStdString(),
      userData.at(6).toStdString(), userData.at(7).toStdString(), userData.at(8).toStdString()};

  if (clientIdentitiesWindowMode == ClientIdentitiesWindowMode::CREATE) {
    dataBaseClient->createUser(std::move(model));
  } else {
    dataBaseClient->updateUser(std::move(model));
  }
}

void WindowManager::setClientIdentitiesWindowVisibility(bool isVisible,
                                                        ClientIdentitiesWindowMode mode) {
  clientIdentitiesWindowVisibility = isVisible;
  clientIdentitiesWindowMode = mode;
  emit clientIdentitiesWindowVisibilityChanged();
}
