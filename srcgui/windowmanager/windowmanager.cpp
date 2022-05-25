#include "windowmanager.h"

void WindowManager::setClientIdentitiesWindowVisibility(bool isVisible) {
  clientIdentitiesWindowVisibility = isVisible;
  emit clientIdentitiesWindowVisibilityChanged();
}
