import QtQuick 2.12

import "../configuration"
import "../inputcomponent"

Rectangle {
    id: clientServiceView
    anchors.fill: parent
    color: ColorConstants.extraLightGrey

    Column {
        id: authorsColumn
        anchors.centerIn: parent
        spacing: 20

        InputComponent {
            id: firstAuthor
            labelText: "Author:"
            placeholderFieldText: "First name and last name"
            contentFieldText: "Wojciech Jarzyna"
        }

        InputComponent {
            id: secondAuthord
            labelText: "Author:"
            placeholderFieldText: "First name and last name"
            contentFieldText: "Jakub Półtoraczyk"
        }
    }
}
