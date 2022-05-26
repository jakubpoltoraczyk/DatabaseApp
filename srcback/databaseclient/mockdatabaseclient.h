#pragma once

#include "databaseclient.h"

class MockDataBaseClient : public DataBaseClient {
public:
  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  void createOrder(Models::OrderModel model) override;

  /**
   * @brief Create user using specified data model
   * @param model Data model related to user which will be created
   */
  void createClient(Models::UserModel model) override;

  /**
   * @brief Delete user with specified pesel number
   * @param pesel Pesel number of user which will be deleted
   */
  void deleteClient(const std::string& pesel) override;

  /**
   * @brief Update user with specified data model
   * @param model Data model which will be used to update user
   */
  void updateClient(Models::UserModel model) override;

  /**
   * @brief Provide a document with available users
   * @return JSON document of available users
   */
  QJsonDocument readClients() override;
};
