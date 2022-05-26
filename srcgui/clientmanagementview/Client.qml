import QtQuick 2.12
import QtQuick.Controls 2.15

import "../configuration"
import "../inputcomponent"
import "../custombutton"

Rectangle {
    id: clientRow
    height: 100
    width: ApplicationWindowConstants.defaultWidth

    property string firstName: ""
    property string lastName: ""
    property string pesel: ""
    property string phoneNumber: ""
    property string mailAdress: ""
    property string city: ""
    property string postalCode: ""
    property string street: ""
    property string houseNumber: ""

    signal deleteClient(string clientPesel)
    signal updateClient(var clientData)

    function collectData() {
        var clientData = []
        clientData.push(firstName)
        clientData.push(lastName)
        clientData.push(pesel)
        clientData.push(phoneNumber)
        clientData.push(mailAdress)
        clientData.push(city)
        clientData.push(postalCode)
        clientData.push(street)
        clientData.push(houseNumber)
        return clientData
    }

    Component.onCompleted: {
        deleteClient.connect(clientManagementViewController.onDeleteButtonReleased)
        updateClient.connect(clientManagementViewController.onUpdateButtonReleased)
    }

    Row {
        id: infoRow
        spacing: 20
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter

        InputComponent {
            id: firstNameComponent
            labelText: "First name:"
            contentFieldText: firstName
        }

        InputComponent {
            id: lastNameComponent
            labelText: "Last name:"
            contentFieldText: lastName
        }
    }

    Row {
        id: actionRow
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        bottomPadding: 20

        CustomButton {
            id: deleteButton
            text: "Delete"

            onReleased: {
                deleteClient(pesel)
            }
        }

        CustomButton {
            id: updateButton
            text: "Update"

            onReleased: {
                updateClient(collectData())
            }
        }
    }
}
