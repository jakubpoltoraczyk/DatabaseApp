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
        clientServiceViewController.orderID = inputComponentRepeater.itemAt(0).contentFieldText
        clientServiceViewController.licenseNumber = inputComponentRepeater.itemAt(1).contentFieldText
        clientServiceViewController.variantID = inputComponentRepeater.itemAt(2).contentFieldText
        clientServiceViewController.orderDate = inputComponentRepeater.itemAt(3).contentFieldText
        clientServiceViewController.receptionDate = inputComponentRepeater.itemAt(4).contentFieldText
        clientServiceViewController.price = inputComponentRepeater.itemAt(5).contentFieldText
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

        Repeater {
            id: inputComponentRepeater
            model: 6

            InputComponent {
                labelText: ClientServiceViewConstants.orderDatasetTextLabelArray[index]
                placeholderFieldText: ClientServiceViewConstants.orderDatasetPlaceholderArray[index]
            }
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
                for(let i = 0; i < inputComponentRepeater.count; ++i) {
                    inputComponentRepeater.itemAt(i).clearContent();
                }
            }
        }

        CustomButton {
            id: makeOrderButton
            text: "Make order"
        }
    }
}
