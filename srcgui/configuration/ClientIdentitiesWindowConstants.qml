pragma Singleton
import QtQuick 2.12

QtObject {
    /** Default width of client identities window */
    readonly property int defaultWidth: 600

    /** Default height of client identities window */
    readonly property int defaultHeight: 500

    /** Contains text for text labels */
    readonly property var textLabelArray:
        ["First name:", "Last name:", "Pesel:", "Phone number:", "Mail adress:", "City:", "Postal code:", "Street:", "House number:"]

    readonly property var placeholderArray:
        ["Jan", "Kowalski", "15310528737", "024335668", "jankowalski@gmail.com", "Wrocław", "60-350", "Plac Grunwaldzki", "22"]
}
