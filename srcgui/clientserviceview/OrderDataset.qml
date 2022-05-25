import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Item {
    id: orderDataset
    width: ClientServiceViewConstants.defaultWidth
    height: ClientServiceViewConstants.orderDatasetHeight

    /** Collect data from each input component */
    function collectData() {
        clientServiceViewController.orderID = orderIdInputComponent.contentFieldText
        clientServiceViewController.licenseNumber = licenseNumberInputComponent.contentFieldText
        clientServiceViewController.variantID = variantIDInputComponent.contentFieldText
        clientServiceViewController.orderDate = orderDateInputComponent.contentFieldText
        clientServiceViewController.receptionDate = receptionDateInputComponent.contentFieldText
        clientServiceViewController.price = priceInputComponent.contentFieldText
    }

    /** Called when component has been just created */
    Component.onCompleted: {
       makeOrderButton.released.connect(clientServiceViewController.onMakeOrderButtonReleased)
    }

    Grid {
        id: inputComponentGrid
        rows: 3
        columns: 2
        rowSpacing: ClientServiceViewConstants.rowSpacing
        columnSpacing: ClientServiceViewConstants.columnSpacing
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 60

        InputComponent {
            id: orderIdInputComponent
            labelText: "Order ID:"
            placeholderFieldText: "10221345"
        }

        InputComponent {
            id: licenseNumberInputComponent
            labelText: "License number:"
            placeholderFieldText: "A452R"
        }

        InputComponent {
            id: variantIDInputComponent
            labelText: "Variant ID:"
            placeholderFieldText: "149928"
        }

        InputComponent {
            id: orderDateInputComponent
            labelText: "Order date:"
            placeholderFieldText: "21.06.2022"
        }

        InputComponent {
            id: receptionDateInputComponent
            labelText: "Reception date:"
            placeholderFieldText: "30.06.2022"
        }

        InputComponent {
            id: priceInputComponent
            labelText: "Price:"
            placeholderFieldText: "1857"
        }
    }

    Row {
        id: customButtonRow
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        bottomPadding: 60
        rightPadding: 60

        CustomButton {
            id: resetButton
            text: "Reset"

            /** Called when button has been released */
            onReleased: {
                orderIdInputComponent.clearContent()
                licenseNumberInputComponent.clearContent()
                variantIDInputComponent.clearContent()
                orderDateInputComponent.clearContent()
                receptionDateInputComponent.clearContent()
                priceInputComponent.clearContent()
            }
        }

        CustomButton {
            id: makeOrderButton
            text: "Make order"
        }
    }
}
