#pragma once

#include "databaseclient.h"

class SQLDataBaseClient : public DataBaseClient {
public:
  /**
   * @brief Send a login request
   * @param login User's login
   * @param password User's password
   * @param Selected login credentials in regard to data base answer
   */
  LoginCredentials requestLogin(const std::string& login, const std::string& password) override;

  /** Send a logout request */
  void requestLogout() override;

  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  void createOrder(Models::OrderModel model) override;

  /**
   * @brief Delete order with specified ID
   * @param Order ID which will be deleted
   */
  void deleteOrder(const std::string& orderID) override;

  /**
   * @brief Complete order with specified ID
   * @param Order ID which will be marked as completed
   */
  void completeOrder(const std::string& orderID) override;

  /**
   * @brief Provide a document with available orders
   * @return JSON document of available orders
   */
  QJsonDocument readOrders() override;

  /**
   * @brief createClient Create user using specified data model
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
