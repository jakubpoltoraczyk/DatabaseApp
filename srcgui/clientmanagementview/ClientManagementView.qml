import QtQuick 2.0
import QtQuick.Controls 2.12

import "../configuration"

ScrollView {
    width: 200
    height: 200
    topPadding: 20
    bottomPadding: 20

    ListView {
        id: clientListView
        model: 25
        spacing: 25
        cacheBuffer: (model + 5) * 100
        delegate: Client {}

        function updateView(newModels) {
            for(let i = 0; i < newModels.length; ++i) {
                clientListView.itemAtIndex(i).firstName = newModels[i].firstName
                clientListView.itemAtIndex(i).lastName = newModels[i].lastName
                clientListView.itemAtIndex(i).pesel = newModels[i].pesel
                clientListView.itemAtIndex(i).phoneNumber = newModels[i].phoneNumber
                clientListView.itemAtIndex(i).mailAdress = newModels[i].mailAdress
                clientListView.itemAtIndex(i).city = newModels[i].city
                clientListView.itemAtIndex(i).postalCode = newModels[i].postalCode
                clientListView.itemAtIndex(i).street = newModels[i].street
                clientListView.itemAtIndex(i).houseNumber = newModels[i].houseNumber
            }
        }

        Connections {
            target: clientManagementViewController

            function onViewChanged(newModels) {
                clientListView.updateView(newModels)
            }
        }
    }
}
