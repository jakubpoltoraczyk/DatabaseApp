import QtQuick 2.12
import QtQuick.Dialogs 1.1

MessageDialog {
    id: messageDialog
    title: customMessageDialogController.title
    text: customMessageDialogController.content
    standardButtons: StandardButton.Ok
    icon: StandardIcon.Information
    visible: customMessageDialogController.visibility

    onAccepted: {
        customMessageDialogController.visibility = false
    }
}
