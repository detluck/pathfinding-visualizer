pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "../theme"

Button {
    id: root

    property color hoverColor: Theme.current.hoverBtn
    property color textColor: Theme.current.textPrimary
    property color backgroundColor: "transparent"
    property alias radius: background.radius
    property alias fontSize: label.font.pixelSize
    property string svgPath: ""
    property color squareColor: "transparent"
    property bool useSquare: false
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
        color: root.hovered || root.highlighted ? root.hoverColor : root.backgroundColor
        border.width: 0
        radius: 12
    }

    // Wir setzen die Row direkt als contentItem
    contentItem: Row {
        spacing: 8

        // Da die Row das contentItem ist, richtet sie sich
        // automatisch nach den Paddings des Buttons aus.

        Rectangle {
            visible: root.useSquare
            height: root.iconSize
            width: root.iconSize
            color: root.squareColor
            border.color: root.borderColor
            radius: 2
            anchors.verticalCenter: parent.verticalCenter
        }

        Image {
            id: svgIcon
            source: root.svgPath
            height: root.iconSize
            width: root.iconSize
            sourceSize.height: height
            sourceSize.width: width
            fillMode: Image.PreserveAspectFit
            visible: root.svgPath !== "" && !root.useSquare
            anchors.verticalCenter: parent.verticalCenter
        }

        StyledText {
            id: label
            text: root.text
            color: root.textColor
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    function changeCursor() {
        if (svgPath !== "") {
            cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
        }
    }
}
