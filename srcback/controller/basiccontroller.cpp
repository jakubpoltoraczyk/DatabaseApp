#include "basiccontroller.h"

BasicController::BasicController(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient),
      windowManager(std::make_shared<WindowManager>(dataBaseClient)),
      clientServiceViewController(dataBaseClient, windowManager),
      clientManagementViewController(dataBaseClient, windowManager) {}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{"basicController", this},
          {"clientServiceViewController", &clientServiceViewController},
          {"clientManagementViewController", &clientManagementViewController},
          {"windowManager", windowManager.get()}};
}

void BasicController::onTabViewChanged(int index) {
  if (index == 1) {
    clientManagementViewController.updateView();
  }
}
