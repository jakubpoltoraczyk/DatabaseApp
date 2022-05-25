import QtQuick 2.12
import QtQuick.Controls 2.12

import "../configuration"
import "../rectanglesolidborder"

Button {
    id: customButton
    width: CustomButtonConstants.defaultWidth
    height: CustomButtonConstants.defaultHeight
    state: CustomButtonConstants.releasedState
    palette.button: ColorConstants.lightGrey

    states: [
        State {
            name: CustomButtonConstants.pressedState
            PropertyChanges {
                target: solidBorder
                topBorderColor: ColorConstants.darkGrey
                rightBorderColor: ColorConstants.white
                bottomBorderColor: ColorConstants.white
                leftBorderColor: ColorConstants.darkGrey
            }
        },
        State {
            name: CustomButtonConstants.releasedState
            PropertyChanges {
                target: solidBorder
                topBorderColor: ColorConstants.white
                rightBorderColor: ColorConstants.darkGrey
                bottomBorderColor: ColorConstants.darkGrey
                leftBorderColor: ColorConstants.white
            }
        }
    ]

    /** Called, when button has been pressed */
    onPressed: {
        state = CustomButtonConstants.pressedState
    }

    /** Called, when button has been released */
    onReleased: {
        state = CustomButtonConstants.releasedState
    }

    /** Called, when button has been canceled */
    onCanceled: {
        state = CustomButtonConstants.releasedState
    }

    RectangleSolidBorder {
        id: solidBorder
    }
}
