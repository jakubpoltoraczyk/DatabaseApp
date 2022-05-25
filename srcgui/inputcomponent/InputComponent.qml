import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"

Row {
    id: inputComponent
    spacing: 5

    /** Label text displayed in the input component */
    property string labelText: ""

    /** Placeholder field text displayed in the input component */
    property string placeholderFieldText: ""

    /** Content field text of the input component */
    property alias contentFieldText: inputComponentField.text

    /** Clear text content of input component field */
    function clearContent() {
        inputComponentField.text = ""
    }

    Label {
        id: inputComponentLabel
        width: InputComponentConstants.inputComponentLabelWidth
        height: InputComponentConstants.inputComponentHeight
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        color: ColorConstants.black
        text: labelText
    }

    TextField {
        id: inputComponentField
        width: InputComponentConstants.inputComponentFieldWidth
        height: InputComponentConstants.inputComponentHeight
        placeholderText: placeholderFieldText
        background: Rectangle {
            id: inputComponentFieldBackground
            color: ColorConstants.white
            border {
                color: ColorConstants.lightGrey
                width: SharedConstants.defaultBorderWidth
            }
        }
    }
}
