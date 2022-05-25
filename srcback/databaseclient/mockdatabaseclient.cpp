#include "mockdatabaseclient.h"

#include <iostream>

void MockDataBaseClient::createOrder([[maybe_unused]] Models::OrderModel model) {
  std::cout << "OrderModel: {" << model.pesel << ", " << model.orderID << ", "
            << model.licenseNumber << ", " << model.variantID << ", " << model.orderDate << ", "
            << model.receptionDate << ", " << model.price << "}" << std::endl;
}
