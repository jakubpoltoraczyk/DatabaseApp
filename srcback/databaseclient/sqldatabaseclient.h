#pragma once

#include "databaseclient.h"

class SQLDataBaseClient : public DataBaseClient {
public:
  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  void createOrder(Models::OrderModel model) override;

  /**
   * @brief createUser Create user using specified data model
   * @param model Data model related to user which will be created
   */
  void createUser(Models::UserModel model) override;
};
