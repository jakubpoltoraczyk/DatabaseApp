import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Item {
    id: clientIdentities
    width: ClientServiceViewConstants.defaultWidth
    height: ClientServiceViewConstants.clientIdentitiestHeight

    /** Collect data from each input component */
    function collectData() {
        clientServiceViewController.firstName = firstNameInputComponent.contentFieldText
        clientServiceViewController.lastName = lastNameInputComponent.contentFieldText
        clientServiceViewController.pesel = peselInputComponent.contentFieldText
        clientServiceViewController.phoneNumber = phoneNumberInputComponent.contentFieldText
    }

    /** Called when component has been just created */
    Component.onCompleted: {
        registerButton.released.connect(clientServiceViewController.onRegisterButtonReleased)
    }

    Grid {
        id: inputComponentGrid
        rows: 2
        columns: 2
        rowSpacing: ClientServiceViewConstants.rowSpacing
        columnSpacing: ClientServiceViewConstants.columnSpacing
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 40

        InputComponent {
            id: firstNameInputComponent
            labelText: "First name:"
            placeholderFieldText: "Jan"
        }

        InputComponent {
            id: lastNameInputComponent
            labelText: "Last name:"
            placeholderFieldText: "Kowalski"
        }

        InputComponent {
            id: peselInputComponent
            labelText: "PESEL:"
            placeholderFieldText: "15310528737"
        }

        InputComponent {
            id: phoneNumberInputComponent
            labelText: "Phone number:"
            placeholderFieldText: "024335668"
        }
    }

    Row {
        id: customButtonRow
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        bottomPadding: 20
        rightPadding: 60

        CustomButton {
            id: resetButton
            text: "Reset"

            /** Called when button has been released */
            onReleased: {
                firstNameInputComponent.clearContent()
                lastNameInputComponent.clearContent()
                peselInputComponent.clearContent()
                phoneNumberInputComponent.clearContent()
            }
        }

        CustomButton {
            id: registerButton
            text: "Register"
        }
    }
}
