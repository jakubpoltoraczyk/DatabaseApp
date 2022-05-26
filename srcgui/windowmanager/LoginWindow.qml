import QtQuick 2.12
import QtQuick.Window 2.12

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Window {
    id: loginWindow
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    width: ApplicationWindowConstants.defaultWidth
    height: ApplicationWindowConstants.defaultHeight
    flags: Qt.Window | Qt.FramelessWindowHint

    /** Emitted, when login button has been released */
    signal loginButtonReleased(string loginText, string passwordText)

    /** Called, when component has been created */
    Component.onCompleted: {
        loginButtonReleased.connect(windowManager.onLoginButtonReleased)
        exitButton.released.connect(windowManager.onExitButtonReleased)
    }

    Column {
        id: inputCompomentsColumn
        spacing: 20
        anchors.centerIn: parent

        InputComponent {
            id: loginInputComponent
            labelText: "Login:"
            placeholderFieldText: "Enter your login"
        }

        InputComponent {
            id: passwordInputComponent
            labelText: "Password:"
            placeholderFieldText: "Enter your password"
            isPasswordModeEnabled: true
        }
    }

    Row {
        id: buttonsRow
        spacing: 25
        anchors.top: inputCompomentsColumn.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        topPadding: 25

        CustomButton {
            id: exitButton
            text: "Exit"
        }

        CustomButton {
            id: loginButton
            text: "Login"

            onReleased: {
                loginButtonReleased(loginInputComponent.contentFieldText,
                                    passwordInputComponent.contentFieldText)
            }
        }
    }
}
