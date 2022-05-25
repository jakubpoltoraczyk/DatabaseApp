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
        clientServiceViewController.firstName = inputComponentRepeater.itemAt(0).contentFieldText
        clientServiceViewController.lastName = inputComponentRepeater.itemAt(1).contentFieldText
        clientServiceViewController.pesel = inputComponentRepeater.itemAt(2).contentFieldText
        clientServiceViewController.phoneNumber = inputComponentRepeater.itemAt(3).contentFieldText
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

        Repeater {
            id: inputComponentRepeater
            model: 4

            InputComponent {
                labelText: ClientServiceViewConstants.clientIdentitiesTextLabelArray[index]
                placeholderFieldText: ClientServiceViewConstants.clientIdentitiesPlaceHolderArray[index]
            }
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
                for(let i = 0; i < inputComponentRepeater.count; ++i) {
                    inputComponentRepeater.itemAt(i).clearContent();
                }
            }
        }

        CustomButton {
            id: registerButton
            text: "Register"
        }
    }
}
