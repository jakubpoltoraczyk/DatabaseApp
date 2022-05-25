#include "basiccontroller.h"

BasicController::BasicController(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient), windowManager(std::make_shared<WindowManager>()),
      clientServiceViewController(dataBaseClient, windowManager) {}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{"clientServiceViewController", &clientServiceViewController},
          {"windowManager", windowManager.get()}};
}
