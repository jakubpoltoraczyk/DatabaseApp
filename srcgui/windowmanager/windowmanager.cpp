#include "windowmanager.h"

#include <QDebug>

WindowManager::WindowManager(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient) {}

void WindowManager::onRegisterUserConfirmed([[maybe_unused]] const QStringList& userData) {
  emit setClientIdentitiesWindowVisibility(false);
  auto model = Models::UserModel{
      userData.at(0).toStdString(), userData.at(1).toStdString(), userData.at(2).toStdString(),
      userData.at(3).toStdString(), userData.at(4).toStdString(), userData.at(5).toStdString(),
      userData.at(6).toStdString(), userData.at(7).toStdString(), userData.at(8).toStdString()};
  dataBaseClient->createUser(std::move(model));
}

void WindowManager::setClientIdentitiesWindowVisibility(bool isVisible) {
  clientIdentitiesWindowVisibility = isVisible;
  emit clientIdentitiesWindowVisibilityChanged();
}
