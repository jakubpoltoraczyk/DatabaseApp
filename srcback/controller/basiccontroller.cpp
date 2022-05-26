#include "basiccontroller.h"

BasicController::BasicController(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient),
      customMessageDialogController(std::make_shared<CustomMessageDialogController>()),
      windowManager(std::make_shared<WindowManager>(dataBaseClient, customMessageDialogController)),
      clientServiceViewController(dataBaseClient, windowManager, customMessageDialogController),
      clientManagementViewController(dataBaseClient, windowManager),
      orderManagementViewController(dataBaseClient) {}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{"basicController", this},
          {"customMessageDialogController", customMessageDialogController.get()},
          {"clientServiceViewController", &clientServiceViewController},
          {"clientManagementViewController", &clientManagementViewController},
          {"orderManagementViewController", &orderManagementViewController},
          {"windowManager", windowManager.get()}};
}

void BasicController::onTabViewChanged(int index) {
  switch (index) {
  case 1:
    clientManagementViewController.updateView();
    break;
  case 2:
    orderManagementViewController.updateView();
    break;
  case 4:
    dataBaseClient->requestLogout();
    windowManager->setLoginWindowVisibility(true);
    emit resetTabView();
    break;
  }
}
