import QtQuick 2.0
import QtQuick.Controls 2.12

import "../configuration"

ScrollView {
    width: 200
    height: 200
    topPadding: 20
    bottomPadding: 20
    background: Rectangle {
        color: ColorConstants.extraLightGrey
    }

    readonly property int maxNumberOfOrders: 25

    ListView {
        id: orderListView
        model: maxNumberOfOrders
        spacing: 25
        cacheBuffer: (model + 50) * 100
        delegate: Order {
            visible: false
        }

        function updateView(newModels) {
            for(let i = 0; i < newModels.length; ++i) {
                orderListView.itemAtIndex(i).orderID = newModels[i].orderID
                orderListView.itemAtIndex(i).pesel = newModels[i].pesel
                orderListView.itemAtIndex(i).licenseNumber = newModels[i].licenseNumber
                orderListView.itemAtIndex(i).variantID = newModels[i].variantID
                orderListView.itemAtIndex(i).orderDate = newModels[i].orderDate
                orderListView.itemAtIndex(i).receptionDate = newModels[i].receptionDate
                orderListView.itemAtIndex(i).price = newModels[i].price
                orderListView.itemAtIndex(i).visible = true
            }
            for(let j = newModels.length; j < maxNumberOfOrders; ++j) {
                orderListView.itemAtIndex(j).visible = false
            }
        }

        Connections {
            target: orderManagementViewController

            function onViewChanged(newModels) {
                orderListView.updateView(newModels)
            }
        }
    }
}
