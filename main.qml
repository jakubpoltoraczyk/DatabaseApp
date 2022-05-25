import QtQuick.Window 2.12
import QtQuick 2.12
import QtQuick.Controls 2.12

import "srcgui/configuration"
import "srcgui/mainpage"
import "srcgui/windowmanager"

Window {
    id: mainApplicationWindow
    x: (Screen.width - width) / 2
    y: (Screen.height - height) / 2
    width: ApplicationWindowConstants.defaultWidth
    height: ApplicationWindowConstants.defaultHeight
    minimumWidth: width
    maximumWidth: width
    minimumHeight: height
    maximumHeight: height
    color: ColorConstants.lightGrey
    visible: true

    MainPage {
        id: mainTabBar
    }

    ClientIdentitiesWindow {
        id: clientIdentitiesWindow
        visible: windowManager.clientIdentitiesWindowVisibility
    }
}
