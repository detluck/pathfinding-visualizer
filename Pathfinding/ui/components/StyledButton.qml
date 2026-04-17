pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects
import "../theme"

Button {
    id: root

    property color hoverColor: Theme.primaryHover
    property color backgroundColor: Theme.primary
    property alias radius: background.radius
    property alias fontSize: label.font.pixelSize
    property bool useSquare: false
    property color labelColor: useSquare? Theme.bgBaseReverse: Theme.bgBase
    property string svgPath: ""
    property color squareColor: "transparent"
    property color svgColor: Theme.bgBase
    property string tipText: ""
    property color borderColor: "transparent"

    property int iconSize: 22

    leftPadding: 12
    rightPadding: 12
    topPadding: 8
    bottomPadding: 8

    hoverEnabled: true
    ToolTip.visible: hovered && tipText !== ""
    ToolTip.text: tipText
    ToolTip.delay: 500

    background: Rectangle {
        id: background
        anchors.fill: parent
        color: (root.hovered || root.highlighted) ? root.hoverColor : (root.useSquare ? "transparent" : root.backgroundColor)
        border.width: 0
        radius: 20
    }

    contentItem: Row {
        spacing: 8

        Rectangle {
            visible: root.useSquare
            height: root.iconSize
            width: root.iconSize
            color: root.squareColor
            border.color: root.borderColor
            radius: 2
            anchors.verticalCenter: parent.verticalCenter

            Behavior on color {
                ColorAnimation { duration: 150 }
            }
        }

        Item {
            height: root.iconSize
            width: root.iconSize
            anchors.verticalCenter: parent.verticalCenter
            visible: root.svgPath !== "" && !root.useSquare

            Image {
                id: svgIcon
                source: root.svgPath
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
                colorizationColor: root.svgColor

                Behavior on colorizationColor {
                    ColorAnimation {
                        duration: 250
                    }
                }
            }
        }

        StyledText {
            id: label
            text: root.text
            color: root.labelColor
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    function changeCursor() {
        if (svgPath !== "") {
            cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
        }
    }
}
