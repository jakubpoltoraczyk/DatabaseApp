import QtQuick.Window 2.15
import QtQuick 2.15
import QtQuick.Controls 2.15

import "srcgui/configuration"
import "srcgui/mainpage"

Window {
    id: mainApplicationWindow
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
}
