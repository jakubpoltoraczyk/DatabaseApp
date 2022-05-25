#pragma once

#include <QObject>

class WindowManager : public QObject {
  Q_OBJECT
  Q_PROPERTY(bool clientIdentitiesWindowVisibility MEMBER clientIdentitiesWindowVisibility NOTIFY
                 clientIdentitiesWindowVisibilityChanged)
public:
  using QObject::QObject;

  /**
   * @brief Set new visibility for client identities window
   * @param isVisible True if window should be visible, otherwise false
   */
  void setClientIdentitiesWindowVisibility(bool isVisible);

signals:
  /** Emitted when client identities window visibility has been changed */
  void clientIdentitiesWindowVisibilityChanged();

private:
  bool clientIdentitiesWindowVisibility = false;
};
