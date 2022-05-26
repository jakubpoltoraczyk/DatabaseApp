import QtQuick.Window 2.12
import QtQuick 2.12
import QtQuick.Controls 2.12

import "srcgui/configuration"
import "srcgui/mainpage"
import "srcgui/windowmanager"
import "srcgui/custommessagedialog"

Window {
    id: mainApplicationWindow
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    width: ApplicationWindowConstants.defaultWidth
    height: ApplicationWindowConstants.defaultHeight
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowStaysOnBottomHint
    color: ColorConstants.lightGrey
    visible: true

    MainPage {
        id: mainTabBar
    }

    ClientIdentitiesWindow {
        id: clientIdentitiesWindow
        visible: windowManager.clientIdentitiesWindowVisibility
    }

    LoginWindow {
        id: loginWindow
        visible: windowManager.loginWindowVisibility
    }

    CustomMessageDialog {
        id: customMessageDialog
    }
}
