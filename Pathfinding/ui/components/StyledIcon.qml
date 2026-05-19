import QtQuick
import QtQuick.Effects
import QtQuick.Layouts

Item {
    id: root

    property string imageSource: ""
    property color imageColor: "#FFFFFF"

    height: 40
    width: 40
    Layout.alignment: Qt.AlignVCenter
    visible: imageSource !== ""

    Image {
        id: svgIcon
        source: root.imageSource
        sourceSize.height: parent.height
        sourceSize.width: parent.width
        fillMode: Image.PreserveAspectFit
        visible: false
    }

    MultiEffect {
        id: svgEffect
        source: svgIcon
        anchors.fill: parent
        colorization: 1.0
        colorizationColor: root.imageColor

        Behavior on colorizationColor {
            ColorAnimation {
                duration: 250
            }
        }
    }
}
