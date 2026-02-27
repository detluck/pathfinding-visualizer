pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../theme"

Button{
    id: root

    property  color hoverColor: Theme.current.hoverBtn
    property color textColor: Theme.current.textPrimary
    property color backgroundColor: "transparent"
    property alias radius: background.radius
    property alias fontSize: label.font.pixelSize
    property string svgPath: ""
    property color squareColor: "transparent"
    property bool useSquare: false
    property string tipText: ""
    property color borderColor: "transparent"

    width: 70
    height: 20
    hoverEnabled: true
    ToolTip.visible: hovered && tipText !== ""
    ToolTip.text: tipText
    ToolTip.delay: 500

    background: Rectangle{
        id: background
        anchors.fill:  parent
        color: root.hovered? root.hoverColor: root.backgroundColor
        border.width: 0
        radius: 12
    }

    contentItem: RowLayout{
        anchors.centerIn: parent
        spacing: 8
            Rectangle{
                visible: root.useSquare
                height: root.height - 4
                width: height
                color: root.squareColor
                Layout.alignment: verticalCenter
                border.color: root.borderColor
            }
            Image {
                id: svgIcon
                source: root.svgPath
                height: root.height - 4
                width: height
                sourceSize.height: height
                sourceSize.width: width
                Layout.alignment: verticalAlignment
                fillMode: Image.PreserveAspectFit
                visible: root.svgPath !== "" && !root.useSquare
                asynchronous: true
            }
           StyledText{
            id: label
            text: root.text
            Layout.alignment: verticalAlignment
        }
    }
}
