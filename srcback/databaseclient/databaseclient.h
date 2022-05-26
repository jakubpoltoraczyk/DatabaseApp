#pragma once

#include "../models.h"

#include <QJsonDocument>

class DataBaseClient {
public:
  /** Contains available login credentials */
  enum class LoginCredentials { UKNOWN, USER, ADMIN };

  /**
   * @brief Send a login request
   * @param login User's login
   * @param password User's password
   * @param Selected login credentials in regard to data base answer
   */
  virtual LoginCredentials requestLogin(const std::string& login, const std::string& password) = 0;

  /** Send a logout request */
  virtual void requestLogout() = 0;

  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  virtual void createOrder(Models::OrderModel model) = 0;

  /**
   * @brief Delete order with specified ID
   * @param Order ID which will be deleted
   */
  virtual void deleteOrder(const std::string& orderID) = 0;

  /**
   * @brief Complete order with specified ID
   * @param Order ID which will be marked as completed
   */
  virtual void completeOrder(const std::string& orderID) = 0;

  /**
   * @brief Provide a document with available orders
   * @return JSON document of available orders
   */
  virtual QJsonDocument readOrders() = 0;

  /**
   * @brief Create user using specified data model
   * @param model Data model related to user which will be created
   */
  virtual void createClient(Models::UserModel model) = 0;

  /**
   * @brief Delete user with specified pesel number
   * @param pesel Pesel number of user which will be deleted
   */
  virtual void deleteClient(const std::string& pesel) = 0;

  /**
   * @brief Update user with specified data model
   * @param model Data model which will be used to update user
   */
  virtual void updateClient(Models::UserModel model) = 0;

  /**
   * @brief Provide a document with available users
   * @return JSON document of available users
   */
  virtual QJsonDocument readClients() = 0;
};
