#pragma once

#include "../../srcgui/clientserviceview/clientserviceviewcontroller.h"

#include <QObject>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
public:
  using QObject::QObject;

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of objects to register
   */
  std::vector<std::pair<QString, QObject*>> getObjectsToRegister();

private:
  ClientServiceViewController clientServiceViewController;
};
