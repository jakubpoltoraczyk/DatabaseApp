pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default width of components in client service view */
    readonly property int defaultWidth: ApplicationWindowConstants.defaultWidth

    /** Height of client identities component in client service view */
    readonly property int clientIdentitiestHeight: ApplicationWindowConstants.defaultHeight / 3

    /** Height of order dataset component in client service view */
    readonly property int orderDatasetHeight: ApplicationWindowConstants.defaultHeight / 2

    /** Default row spacing between components in client service view */
    readonly property int rowSpacing: 10

    /** Default column spacing between components in client service view */
    readonly property int columnSpacing: 50

    /** Contains text for text labels in client identities component */
    readonly property var clientIdentitiesTextLabelArray: ["First name:", "Lase name:", "Pesel:", "Phone number:"]

    /** Contains text for placeholders in client identities component */
    readonly property var clientIdentitiesPlaceHolderArray: ["Jan", "Kowalski", "15310528737", "024335668"]

    /** Contains text for text labels in order dataset component */
    readonly property var orderDatasetTextLabelArray:
        ["Order ID:", "License number:", "Variant ID:", "Order date:", "Reception date:", "Price:"]

    /** Contains text for placeholders in order dataset component */
    readonly property var orderDatasetPlaceholderArray:
        ["10221345", "A452R", "149928", "21.06.2022", "30.06.2022", "1857"]
}
