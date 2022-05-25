pragma Singleton
import QtQuick 2.15

QtObject {
    /** Default width of custom button */
    readonly property int defaultWidth: 100

    /** Default height of custom button */
    readonly property int defaultHeight: 40

    /** Pressed state of custom button */
    readonly property string pressedState: "pressedState"

    /** Released state of custom button */
    readonly property string releasedState: "releasedState"
}
