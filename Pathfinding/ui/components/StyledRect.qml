import QtQuick
import QtQuick.Layouts
import "../theme"

Rectangle{
    property  color hoverColor: Theme.colors.hoverBtn
    property color textColor: Theme.colors.textPrimary
    property color backgroundColor: "transparent"
    property color squareColor: "transparent"
    property string text: ""

    id:root
    border.width: 0
    radius: 12
    color: backgroundColor

    Row{
        anchors.centerIn: parent
        spacing: 10
        Rectangle{
            height: root.height -2
            width: height
            color: root.squareColor
            anchors.verticalCenter: parent.verticalCenter
        }
        StyledText{
            id: label
            text: root.text
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}

