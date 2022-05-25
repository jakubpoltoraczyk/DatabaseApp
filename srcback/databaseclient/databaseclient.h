#pragma once

#include "../models.h"

class DataBaseClient {
public:
  virtual void createOrder(Models::OrderModel model) = 0;
};
