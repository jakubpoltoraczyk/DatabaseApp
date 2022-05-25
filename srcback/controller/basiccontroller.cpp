#include "basiccontroller.h"

BasicController::BasicController(std::shared_ptr<DataBaseClient> newDataBaseClient)
    : dataBaseClient(newDataBaseClient), clientServiceViewController(dataBaseClient) {}

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{"clientServiceViewController", &clientServiceViewController}};
}
