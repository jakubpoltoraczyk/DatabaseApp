#include "sqldatabaseclient.h"

#include <iostream>

DataBaseClient::LoginCredentials
SQLDataBaseClient::requestLogin([[maybe_unused]] const std::string& login,
                                [[maybe_unused]] const std::string& password) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return DataBaseClient::LoginCredentials::UKNOWN;
}

void SQLDataBaseClient::requestLogout() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

void SQLDataBaseClient::createOrder([[maybe_unused]] Models::OrderModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void SQLDataBaseClient::deleteOrder([[maybe_unused]] const std::string& orderID) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void SQLDataBaseClient::completeOrder([[maybe_unused]] const std::string& orderID) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

QJsonDocument SQLDataBaseClient::readOrders() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return QJsonDocument();
}

void SQLDataBaseClient::createClient([[maybe_unused]] Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void SQLDataBaseClient::deleteClient([[maybe_unused]] const std::string& pesel) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void SQLDataBaseClient::updateClient([[maybe_unused]] Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
}

QJsonDocument SQLDataBaseClient::readClients() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return QJsonDocument();
}
