pragma Singleton
import QtQuick 2.15

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
}
