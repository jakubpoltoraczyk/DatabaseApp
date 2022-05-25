import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.15

import "../clientserviceview"

Page {
    id: page
    anchors.fill: parent

    header: TabBar {
        id: tabBar
        width: parent.width

        Repeater{
            id: tabBarRepeater
            model: ["Client Service", "SecondTab", "ThirdTab", "FourthTab", "FifthTab"]

            TabButton {
                text: modelData
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
    }
}
