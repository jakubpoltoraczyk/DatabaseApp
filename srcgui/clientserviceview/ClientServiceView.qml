import QtQuick 2.12

import "../configuration"

Rectangle {
    id: clientServiceView
    anchors.fill: parent
    color: ColorConstants.extraLightGrey

    Connections {
        target: clientServiceViewController

        function onCollectDataFromClientIdentitiesComponent() {
            clientIdentities.collectData()
        }

        function onCollectDataFromOrderDatasetComponent() {
            orderDataset.collectData()
        }
    }

    Column {
        id: clientServiceViewColumn

        ClientIdentities {
            id: clientIdentities
        }

        OrderDataset {
            id: orderDataset
        }
    }
}
