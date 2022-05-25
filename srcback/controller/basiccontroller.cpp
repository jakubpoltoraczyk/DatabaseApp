#include "basiccontroller.h"

std::vector<std::pair<QString, QObject*>> BasicController::getObjectsToRegister() {
  return {{"clientServiceViewController", &clientServiceViewController}};
}
