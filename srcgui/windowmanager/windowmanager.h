#pragma once

#include "../../srcback/databaseclient/databaseclient.h"
#include "../../srcgui/custommessagedialog/custommessagedialogcontroller.h"

#include <QObject>
#include <QStringList>

#include <memory>

class WindowManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool clientIdentitiesWindowVisibility MEMBER clientIdentitiesWindowVisibility NOTIFY
                 clientIdentitiesWindowVisibilityChanged)
  Q_PROPERTY(
      bool loginWindowVisibility MEMBER loginWindowVisibility NOTIFY loginWindowVisibilityChanged)

public:
  enum class ClientIdentitiesWindowMode { CREATE, UPDATE };

  /**
   * @brief Create a new instance of window manager
   * @param newDataBaseClient DataBaseClient object to communicate with database
   */
  WindowManager(std::shared_ptr<DataBaseClient> newDataBaseClient,
                std::shared_ptr<CustomMessageDialogController> newCustomMessageDialogController);

  void setClientIdentitiesWindowVisibility(
      bool isVisible, ClientIdentitiesWindowMode mode = ClientIdentitiesWindowMode::CREATE);

  void setLoginWindowVisibility(bool isVisible);

public slots:
  void onRegisterUserConfirmed(const QStringList& userData);

  void onExitButtonReleased();

  void onLoginButtonReleased(const QString& loginText, const QString& passwordText);

signals:
  /** Emitted when client identities window visibility has been changed */
  void clientIdentitiesWindowVisibilityChanged();

  void completeClientIdentitiesWindowData(const QStringList& clientData);

  void loginWindowVisibilityChanged();

  void setApplicationAuthorsButtonState(bool isEnabled);

private:
  bool clientIdentitiesWindowVisibility = false;
  ClientIdentitiesWindowMode clientIdentitiesWindowMode = ClientIdentitiesWindowMode::CREATE;

  bool loginWindowVisibility = true;

  std::shared_ptr<DataBaseClient> dataBaseClient;
  std::shared_ptr<CustomMessageDialogController> customMessageDialogController;
};
