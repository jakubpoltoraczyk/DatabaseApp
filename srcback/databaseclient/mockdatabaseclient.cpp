#include "mockdatabaseclient.h"

#include <iostream>

void MockDataBaseClient::createOrder(Models::OrderModel model) {
  std::cout << "OrderModel: {" << model.pesel << ", " << model.orderID << ", "
            << model.licenseNumber << ", " << model.variantID << ", " << model.orderDate << ", "
            << model.receptionDate << ", " << model.price << "}" << std::endl;
}

void MockDataBaseClient::createUser([[maybe_unused]] Models::UserModel model) {
  std::cout << "UserModel: {" << model.firstName << ", " << model.lastName << ", " << model.pesel
            << ", " << model.phoneNumber << ", " << model.mailAdress << ", " << model.city << ", "
            << model.postalCode << ", " << model.street << ", " << model.houseNumber << "}"
            << std::endl;
}
