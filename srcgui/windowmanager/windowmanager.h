#pragma once

#include "../../srcback/databaseclient/databaseclient.h"

#include <QObject>
#include <QStringList>

#include <memory>

class WindowManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool clientIdentitiesWindowVisibility MEMBER clientIdentitiesWindowVisibility NOTIFY
                 clientIdentitiesWindowVisibilityChanged)
public:
  /**
   * @brief Create a new instance of window manager
   * @param newDataBaseClient DataBaseClient object to communicate with database
   */
  WindowManager(std::shared_ptr<DataBaseClient> newDataBaseClient);

  /**
   * @brief Set new visibility for client identities window
   * @param isVisible True if window should be visible, otherwise false
   */
  void setClientIdentitiesWindowVisibility(bool isVisible);

public slots:
  void onRegisterUserConfirmed(const QStringList &userData);

signals:
  /** Emitted when client identities window visibility has been changed */
  void clientIdentitiesWindowVisibilityChanged();

  /**
   * @brief Complete client identities window data
   * @param firstName First name to complete
   * @param lastName Last name to complete
   * @param pesel Pesel to complete
   * @param phoneNumber Phone number to complete
   */
  void completeClientIdentitiesWindowData(const QString& firstName, const QString& lastName,
                                          const QString& pesel, const QString& phoneNumber);

private:
  bool clientIdentitiesWindowVisibility = false;

  std::shared_ptr<DataBaseClient> dataBaseClient;
};
