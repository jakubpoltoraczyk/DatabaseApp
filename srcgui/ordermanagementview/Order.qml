import QtQuick 2.12
import QtQuick.Controls 2.15

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Rectangle {
    id: clientRow
    height: 200
    width: ApplicationWindowConstants.defaultWidth
    color: ColorConstants.extraLightGrey

    signal deleteOrder(string deleteOrderID)
    signal completeOrder(string completeOrderID)

    property string orderID: ""
    property string pesel: ""
    property string licenseNumber: ""
    property string variantID: ""
    property string orderDate: ""
    property string receptionDate: ""
    property string price: ""

    Component.onCompleted: {
        deleteOrder.connect(orderManagementViewController.onDeleteButtonReleased)
        completeOrder.connect(orderManagementViewController.onCompleteButtonReleased)
    }

    Grid {
        id: inputComponentGrid
        rows: 3
        columns: 2
        rowSpacing: 10
        columnSpacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        InputComponent {
            labelText: "Order ID:"
            contentFieldText: orderID
        }

        InputComponent {
            labelText: "License number:"
            contentFieldText: licenseNumber
        }

        InputComponent {
            labelText: "Variant ID:"
            contentFieldText: variantID
        }

        InputComponent {
            labelText: "Order date:"
            contentFieldText: orderDate
        }

        InputComponent {
            labelText: "Reception date:"
            contentFieldText: receptionDate
        }

        InputComponent {
            labelText: "Price:"
            contentFieldText: price
        }
    }

    Row {
        id: actionRow
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        bottomPadding: 40

        CustomButton {
            id: deleteButton
            text: "Delete"

            onReleased: {
                deleteOrder(orderID)
            }
        }

        CustomButton {
            id: completeButton
            text: "Complete"

            onReleased: {
                completeOrder(orderID)
            }
        }
    }
}
