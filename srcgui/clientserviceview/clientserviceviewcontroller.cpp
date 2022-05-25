#include "clientserviceviewcontroller.h"

#include <QDebug>

void ClientServiceViewController::onRegisterButtonReleased() {
}

void ClientServiceViewController::onMakeOrderButtonReleased() {
  emit collectDataFromGUI();
}
