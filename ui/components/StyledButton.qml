pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import "../theme"

Button{
    id: root

    property  color hoverColor: Theme.colors.hoverBtn
    property color textColor: Theme.colors.textPrimary
    property color backgroundColor: "transparent"
    property alias radius: background.radius
    property alias fontSize: label.font.pixelSize
    property url svgPath: ""
    property color squareColor: "transparent"
    property bool useSquare: false

    width: 200
    height: 200

    background: Rectangle{
        id: background
        anchors.fill:  parent
        color: root.hovered? root.hoverColor: root.backgroundColor
        border.width: 0
        radius: 12
    }

    contentItem: Row{
        anchors.centerIn: parent
        spacing: 8
            Rectangle{
                visible: root.useSquare
                height: root.height -2
                width: height
                color: root.squareColor
                anchors.verticalCenter: parent.verticalCenter
            }
            Image {
                id: svgIcon
                source: root.svgPath
                height: Math.min(root.height - 2, 64)
                width: height
                sourceSize.height: height
                sourceSize.width: width
                anchors.verticalCenter: parent.verticalCenter
                fillMode: Image.PreserveAspectFit
                visible: root.svgPath !== "" && !root.useSquare
                asynchronous: true
            }
           StyledText{
            id: label
            text: root.text
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
