#pragma once

#include "../models.h"

class DataBaseClient {
public:
  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  virtual void createOrder(Models::OrderModel model) = 0;

  /**
   * @brief createUser Create user using specified data model
   * @param model Data model related to user which will be created
   */
  virtual void createUser(Models::UserModel model) = 0;
};
