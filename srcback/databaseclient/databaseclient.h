#pragma once

#include "../models.h"

#include <QJsonDocument>

class DataBaseClient {
public:
  /**
   * @brief Create order using specified data model
   * @param model Data model related to order which will be created
   */
  virtual void createOrder(Models::OrderModel model) = 0;

  /**
   * @brief Create user using specified data model
   * @param model Data model related to user which will be created
   */
  virtual void createClient(Models::UserModel model) = 0;

  /**
   * @brief Delete user with specified pesel number
   * @param pesel Pesel number of user which will be deleted
   */
  virtual void deleteClient(const std::string &pesel) = 0;

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
