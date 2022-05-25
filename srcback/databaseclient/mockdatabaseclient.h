#pragma once

#include "databaseclient.h"

class MockDataBaseClient : public DataBaseClient {
public:
  void createOrder(Models::OrderModel model) override;
};
