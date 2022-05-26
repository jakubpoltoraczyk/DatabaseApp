#include "windowmanager.h"

#include <QApplication>
#include <QDebug>

WindowManager::WindowManager(
    std::shared_ptr<DataBaseClient> newDataBaseClient,
    std::shared_ptr<CustomMessageDialogController> newCustomMessageDialogController)
    : dataBaseClient(newDataBaseClient),
      customMessageDialogController(newCustomMessageDialogController) {}

void WindowManager::onRegisterUserConfirmed(const QStringList& userData) {
  emit setClientIdentitiesWindowVisibility(false, clientIdentitiesWindowMode);
  auto model = Models::UserModel{
      userData.at(0).toStdString(), userData.at(1).toStdString(), userData.at(2).toStdString(),
      userData.at(3).toStdString(), userData.at(4).toStdString(), userData.at(5).toStdString(),
      userData.at(6).toStdString(), userData.at(7).toStdString(), userData.at(8).toStdString()};

  if (clientIdentitiesWindowMode == ClientIdentitiesWindowMode::CREATE) {
    dataBaseClient->createClient(std::move(model));
  } else {
    dataBaseClient->updateClient(std::move(model));
  }
}

void WindowManager::onExitButtonReleased() { QApplication::quit(); }

void WindowManager::onLoginButtonReleased(const QString& loginText, const QString& passwordText) {
  auto loginCredentials =
      dataBaseClient->requestLogin(loginText.toStdString(), passwordText.toStdString());
  switch (loginCredentials) {
  case DataBaseClient::LoginCredentials::UKNOWN:
    customMessageDialogController->showMessageDialog("Login",
                                                     "You've entered invalid login or password!");
    break;
  case DataBaseClient::LoginCredentials::USER:
  case DataBaseClient::LoginCredentials::ADMIN:
    emit setApplicationAuthorsButtonState(loginCredentials ==
                                          DataBaseClient::LoginCredentials::ADMIN);
    setLoginWindowVisibility(false);
    customMessageDialogController->showMessageDialog(
        "Login", "You've logged successfully into application!");
    break;
  }
}

void WindowManager::setClientIdentitiesWindowVisibility(bool isVisible,
                                                        ClientIdentitiesWindowMode mode) {
  clientIdentitiesWindowVisibility = isVisible;
  clientIdentitiesWindowMode = mode;
  emit clientIdentitiesWindowVisibilityChanged();
}

void WindowManager::setLoginWindowVisibility(bool isVisible) {
  loginWindowVisibility = isVisible;
  emit loginWindowVisibilityChanged();
}
