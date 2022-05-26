import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

import "../clientserviceview"
import "../clientmanagementview"
import "../applicationauthorsview"
import "../ordermanagementview"

Page {
    id: page
    anchors.fill: parent

    signal tabViewChanged(int index)

    Component.onCompleted: {
        tabViewChanged.connect(basicController.onTabViewChanged)
    }

    header: TabBar {
        id: tabBar
        currentIndex: 0

        Connections {
            target: basicController

            function onResetTabView() {
                tabBar.currentIndex = 0
            }
        }

        Connections {
            target: windowManager

            function onSetApplicationAuthorsButtonState(isEnabled) {
                tabBarRepeater.itemAt(3).enabled = isEnabled
            }
        }

        Repeater{
            id: tabBarRepeater
            model: ["Client service", "Client management", "Order management", "Application authors", "Logout"]

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
            id: clientManagementView
        }

        OrderManagementView {
            id: orderManagementView
        }

        ApplicationAuthorsView {
            id: applicationAuthorsView
        }
    }
}
