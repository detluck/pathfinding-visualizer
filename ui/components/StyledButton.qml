pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import "../theme"

Button{
    id: root

    property  color hoverColor: Theme.colors.hoverBtn
    property color textColor: Theme.colors.textPrimary
    property color backgroundColor: "transparent"
    property int iconSize: Theme.font.size.icon.normal
    property alias radius: background.radius
    property alias fontSize: label.font.pixelSize
    property url svgPath: ""

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
            Image {
            id: svgIcon
            source: root.svgPath
            height: root.iconSize
            width: root.iconSize
            sourceSize.height: height
            sourceSize.width: width
            anchors.verticalCenter: parent.verticalCenter
            visible: root.svgPath !== ""
        }
           StyledText{
            id: label
            text: root.text
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
