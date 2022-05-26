#pragma once

#include "../../srcback/databaseclient/databaseclient.h"
#include "../windowmanager/windowmanager.h"

#include <QObject>
#include <QVariantList>

#include <memory>

class ClientManagementViewController : public QObject {
  Q_OBJECT
public:
  ClientManagementViewController(std::shared_ptr<DataBaseClient> newDataBaseClient,
                                 std::shared_ptr<WindowManager> newWindowManager);

  void updateView();

public slots:
  void onDeleteButtonReleased(const QString& clientPesel);

  void onUpdateButtonReleased();

signals:
  void viewChanged(QVariantList newModels);

private:
  std::shared_ptr<DataBaseClient> dataBaseClient;
  std::shared_ptr<WindowManager> windowManager;
};
