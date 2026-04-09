pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App.Controller 1.0

Rectangle {
    id: root
    color: "white"

    Layout.fillWidth: true
    Layout.preferredHeight: parent ? parent.height * 0.35 : 280
    Layout.minimumHeight: 180
    Layout.maximumHeight: 350

    Flickable {
        id: flick
        anchors.fill: parent
        anchors.margins: 10

        contentWidth: Math.max(width, mainLayout.implicitWidth)
        contentHeight: height

        flickableDirection: Flickable.HorizontalFlick
        boundsBehavior: Flickable.StopAtBounds
        clip: true

        ColumnLayout {
            id: mainLayout
            width: flick.width
            height: flick.height
            spacing: 20

            RowLayout {
                Layout.fillWidth: true
                spacing: 15

                StyledText {
                    text: "Pathfinding-Visualizer"
                }

                Item { Layout.fillWidth: true }

                SpeedSlider {
                    Layout.preferredWidth: 200
                    onValueChanged: controller.setSpeed(value)
                }

                AlgoSelector {
                    Layout.preferredWidth: 200
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true   // 🔥 wichtig!
                spacing: 40

                ColumnLayout {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 140
                    spacing: 10

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Start"
                        svgPath: "../assets/svgs/start.svg"
                        highlighted: controller.type === Controller.Start
                        onClicked: {
                            controller.setClickType(Controller.Start)
                            controller.handleClick()
                            cursorHelper.resetCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Terminate"
                        svgPath: "../assets/svgs/terminate.svg"
                        highlighted: controller.type === Controller.Stop
                        onClicked: {
                            controller.setClickType(Controller.Stop)
                            controller.handleClick()
                            cursorHelper.resetCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Pause"
                        svgPath: "../assets/svgs/pause.svg"
                        highlighted: controller.type === Controller.Pause
                        onClicked: {
                            controller.setClickType(Controller.Pause)
                            controller.handleClick()
                            cursorHelper.resetCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Clear Grid"
                        svgPath: "../assets/svgs/clean.svg"
                        tipText: "clears the entire grid"
                        highlighted: controller.type === Controller.Clear
                        onClicked: {
                            controller.setClickType(Controller.Clear)
                            controller.handleClick()
                            cursorHelper.resetCursor()
                        }
                    }
                }

                ColumnLayout {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 140
                    spacing: 10

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Start node"
                        svgPath: "../assets/svgs/startNode.svg"
                        highlighted: controller.type === Controller.StartNode
                        onClicked: {
                            controller.setClickType(Controller.StartNode)
                            changeCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Target node"
                        svgPath: "../assets/svgs/endNode.svg"
                        highlighted: controller.type === Controller.TargetNode
                        onClicked: {
                            controller.setClickType(Controller.TargetNode)
                            changeCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Wall"
                        svgPath: "../assets/svgs/wall.svg"
                        highlighted: controller.type === Controller.Wall
                        onClicked: {
                            controller.setClickType(Controller.Wall)
                            changeCursor()
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Delete Item"
                        svgPath: "../assets/svgs/delete.svg"
                        highlighted: controller.type === Controller.Deleate
                        onClicked: {
                            controller.setClickType(Controller.Deleate)
                            changeCursor()
                        }
                    }
                }

                ColumnLayout {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 140
                    spacing: 10

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        borderColor: "skyblue"
                        text: "Unvisited Node"
                        hoverEnabled: false
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        squareColor: "blue"
                        text: "Visited Node"
                        hoverEnabled: false
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        squareColor: "yellow"
                        text: "Shortest Path"
                        hoverEnabled: false
                    }

                    Item { Layout.fillHeight: true }
                }

                // Spacer
                Item {
                    Layout.fillWidth: true
                    visible: mainLayout.implicitWidth < flick.width
                }
            }
        }
    }
}
