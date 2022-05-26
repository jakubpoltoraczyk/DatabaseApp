#include "mockdatabaseclient.h"

#include <iostream>

void MockDataBaseClient::createOrder(Models::OrderModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "OrderModel: {" << model.pesel << ", " << model.orderID << ", "
            << model.licenseNumber << ", " << model.variantID << ", " << model.orderDate << ", "
            << model.receptionDate << ", " << model.price << "}" << std::endl;
}

void MockDataBaseClient::createUser(Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "UserModel: {" << model.firstName << ", " << model.lastName << ", " << model.pesel
            << ", " << model.phoneNumber << ", " << model.mailAdress << ", " << model.city << ", "
            << model.postalCode << ", " << model.street << ", " << model.houseNumber << "}"
            << std::endl;
}

void MockDataBaseClient::deleteUser(const std::string& pesel) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "Pesel: " << pesel << std::endl;
}

void MockDataBaseClient::updateUser(Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "UserModel: {" << model.firstName << ", " << model.lastName << ", " << model.pesel
            << ", " << model.phoneNumber << ", " << model.mailAdress << ", " << model.city << ", "
            << model.postalCode << ", " << model.street << ", " << model.houseNumber << "}"
            << std::endl;
}
