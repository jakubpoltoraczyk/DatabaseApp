import QtQuick 2.12
import QtQuick.Window 2.12

import "../configuration"
import "../inputcomponent"

Window {
    id: clientIdentitiesWindow
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    width: ClientIdentitiesWindowConstants.defaultWidth
    height: ClientIdentitiesWindowConstants.defaultHeight
    flags: Qt.Window | Qt.FramelessWindowHint

    Rectangle {
        id: mainRectangle
        anchors.fill: parent
        color: ColorConstants.white

        Column {
            id: inputComponentColumn
            spacing: 5

            Repeater {
                id: inputComponentRepeater
                model: 9

                InputComponent {
                    labelText: "Some label:"
                    placeholderFieldText: "placeholder"
                }
            }
        }
    }
}
