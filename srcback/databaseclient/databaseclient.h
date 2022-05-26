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
   * @brief Create user using specified data model
   * @param model Data model related to user which will be created
   */
  virtual void createUser(Models::UserModel model) = 0;

  /**
   * @brief Delete user with specified pesel number
   * @param pesel Pesel number of user which will be deleted
   */
  virtual void deleteUser(const std::string &pesel) = 0;

  /**
   * @brief Update user with specified data model
   * @param model Data model which will be used to update user
   */
  virtual void updateUser(Models::UserModel model) = 0;
};
