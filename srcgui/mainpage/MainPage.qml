import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

import "../clientserviceview"
import "../clientmanagementview"

Page {
    id: page
    anchors.fill: parent

    signal tabViewChanged(int index)

    Component.onCompleted: {
        tabViewChanged.connect(basicController.onTabViewChanged)
    }

    header: TabBar {
        id: tabBar
        width: parent.width

        Repeater{
            id: tabBarRepeater
            model: ["Client service", "Client management", "Order management", "Application authors"]

            TabButton {
                text: modelData

                onReleased: {
                    tabViewChanged(index)
                }
            }
        }
    }

    StackLayout {
        id: stackLayout
        currentIndex: tabBar.currentIndex
        anchors.fill: parent

        ClientServiceView {
            id: clientServiceView
        }

        ClientManagementView {

        }
    }
}
