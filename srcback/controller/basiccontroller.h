#pragma once

#include "../../srcgui/clientserviceview/clientserviceviewcontroller.h"
#include "../../srcgui/windowmanager/windowmanager.h"
#include "../databaseclient/databaseclient.h"

#include <QObject>
#include <memory>

/** Class which represents application basic controller */
class BasicController : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Create a new instance of basic controller object
   * @param newDataBaseClient DataBaseClient object to communicate with database
   */
  BasicController(std::shared_ptr<DataBaseClient> newDataBaseClient);

  /**
   * @brief Provide objects to register in QML part of application
   * @return Container of objects to register
   */
  std::vector<std::pair<QString, QObject*>> getObjectsToRegister();

private:
  std::shared_ptr<DataBaseClient> dataBaseClient;
  std::shared_ptr<WindowManager> windowManager;

  ClientServiceViewController clientServiceViewController;
};
