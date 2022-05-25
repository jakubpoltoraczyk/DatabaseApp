import QtQuick 2.12
import QtQuick.Window 2.12

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Window {
    id: clientIdentitiesWindow
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    width: ClientIdentitiesWindowConstants.defaultWidth
    height: ClientIdentitiesWindowConstants.defaultHeight
    flags: Qt.Window | Qt.FramelessWindowHint

    signal registerUserConfirmed(var userData)

    function collectData() {
        let userData = []
        for(let i = 0; i < inputComponentRepeater.count; ++i) {
            userData[i] = inputComponentRepeater.itemAt(i).contentFieldText
        }
        registerUserConfirmed(userData)
    }

    Component.onCompleted: {
        registerUserConfirmed.connect(windowManager.onRegisterUserConfirmed)
    }

    Connections {
        target: windowManager

        function onCompleteClientIdentitiesWindowData(firstName, lastName, pesel, phoneNumber) {
            inputComponentRepeater.itemAt(0).contentFieldText = firstName
            inputComponentRepeater.itemAt(1).contentFieldText = lastName
            inputComponentRepeater.itemAt(2).contentFieldText = pesel
            inputComponentRepeater.itemAt(3).contentFieldText = phoneNumber
        }
    }

    Rectangle {
        id: mainRectangle
        anchors.fill: parent
        color: ColorConstants.white

        Column {
            id: inputComponentColumn
            spacing: 6
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            topPadding: 50

            Repeater {
                id: inputComponentRepeater
                model: 9

                InputComponent {
                    labelText: ClientIdentitiesWindowConstants.textLabelArray[index]
                    placeholderFieldText: ClientIdentitiesWindowConstants.placeholderArray[index]
                }
            }
        }

        CustomButton {
            id: confirmButton
            text: "Confirm"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60

            onReleased: {
                collectData()
            }
        }
    }
}
