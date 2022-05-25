#pragma once

#include "databaseclient.h"

class SQLDataBaseClient : public DataBaseClient {
public:
  void createOrder(Models::OrderModel model) override;
};
