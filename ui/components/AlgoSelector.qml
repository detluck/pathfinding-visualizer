pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import "../theme"
ComboBox{
    id: root

    property  color hoverColor: Theme.surface1
    property color pressedColor: Theme.surface2
    property color textColor: Theme.textMain
    property color backgroundColor: Theme.surface0
    property int bWidth: 100
    property int bHeight: 50

    model: ["Dijkstra", "A*", "BFS"]
    currentIndex: -1

    delegate: ItemDelegate{
        id: delegate

        required property var model
        required property int index

        width: root.width
        contentItem: StyledText{
            text: model.modelData
            color: root.textColor
        }
        highlighted: root.highlightedIndex === index

        background: Rectangle{
            color: delegate.highlighted? root.hoverColor: root.backgroundColor
        }

    }

    contentItem: StyledText{
        leftPadding: 5
        rightPadding: root.indicator.width + root.spacing
        text: currentIndex === -1? "Pick an algorithm": root.displayText
        color: root.pressed? root.pressedColor: root.textColor
    }

    indicator: Canvas {
            id: canvas
            x: root.width - width - root.rightPadding
            y: root.topPadding + (root.availableHeight - height) / 2
            width: 12
            height: 8
            contextType: "2d"

            Connections {
                target: root
                function onPressedChanged() { canvas.requestPaint(); }
            }

            onPaint: {
                context.reset();
                context.moveTo(0, 0);
                context.lineTo(width, 0);
                context.lineTo(width / 2, height);
                context.closePath();
                context.fillStyle = root.pressed ? root.hoverColor : root.textColor;
                context.fill();
            }
    }


    popup: Popup{
        y: root.height - 1
        width: root.width
        height: Math.min(contentItem.implicitHeight, root.Window.height - topMargin - bottomMargin)
        contentItem: ListView{
            clip: true
            implicitHeight: contentHeight
            model: root.popup.visible? root.delegateModel: null
            currentIndex: root.highlightedIndex
        }

        background: Rectangle{
            radius: 10
            color: root.backgroundColor
        }
    }

    background: Rectangle{
        implicitHeight: root.bHeight
        implicitWidth: root.bWidth
        radius: 6
        color: root.backgroundColor
    }

    onCurrentIndexChanged: {
        controller.setAlgorithm(currentIndex);
    }
}
