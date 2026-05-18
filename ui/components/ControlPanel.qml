pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App.Controller 1.0
import Pathfinding

Rectangle {
    id: root
    color: Theme.bgBase

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

                SpeedSlider {
                    Layout.preferredWidth: 230
                    onValueChanged: value => controller.setSpeed(value)
                }

                AlgoSelector {
                    Layout.preferredWidth: 200
                    label: "Pick TSP"
                    model: ["Brute force", "Nearest Neighbor"]
                    onCurrentIndexChanged: {
                        controller.setTspAlgorithm(currentIndex);
                    }
                }

                AlgoSelector {
                    Layout.preferredWidth: 200
                    label: "Pick Pathfinding"
                    model: ["Dijkstra", "A*", "BFS"]
                    onCurrentIndexChanged: {
                        controller.setAlgorithm(currentIndex);
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: true
                Layout.fillHeight: true
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
                            controller.type = Controller.Start;
                            controller.handleClick();
                            cursorHelper.resetCursor();
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Pause"
                        svgPath: "../assets/svgs/pause.svg"
                        highlighted: controller.type === Controller.Pause
                        onClicked: {
                            controller.type = Controller.Pause;
                            controller.handleClick();
                            cursorHelper.resetCursor();
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Delete Item"
                        svgPath: "../assets/svgs/delete.svg"
                        highlighted: controller.type === Controller.Deleate
                        onClicked: {
                            controller.type = Controller.Deleate;
                            changeCursor();
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
                            controller.type = Controller.Clear;
                            controller.handleClick();
                            cursorHelper.resetCursor();
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
                            controller.type = Controller.StartNode;
                            changeCursor();
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Target node"
                        svgPath: "../assets/svgs/endNode.svg"
                        highlighted: controller.type === Controller.TargetNode
                        onClicked: {
                            controller.type = Controller.TargetNode;
                            changeCursor();
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "Wall"
                        svgPath: "../assets/svgs/wall.svg"
                        highlighted: controller.type === Controller.Wall
                        onClicked: {
                            controller.type = Controller.Wall;
                            changeCursor();
                        }
                    }

                    WeightButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }
                }

                ColumnLayout {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 140
                    spacing: 10

                    Switch {
                        id: modeSwitch
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30

                        text: checked ? "TSP Mode" : "Pathfinding Mode"
                        checked: controller.appMode === Controller.TSP

                        onClicked: {
                            controller.appMode = checked ? Controller.TSP : Controller.Pathfinding;
                        }

                        indicator: Rectangle {
                            implicitWidth: 54
                            implicitHeight: 28

                            x: modeSwitch.leftPadding
                            y: parent.height / 2 - height / 2

                            radius: height / 2

                            color: modeSwitch.checked ? Theme.slider : Theme.surface1
                            border.color: modeSwitch.checked ? "#17a81a" : "#d1d1d6"

                            Behavior on color {
                                ColorAnimation {
                                    duration: 200
                                }
                            }

                            Rectangle {
                                y: 2
                                x: modeSwitch.checked ? parent.width - width - 2 : 2

                                width: parent.height - 4
                                height: parent.height - 4
                                radius: width / 2

                                color: Theme.switchFg

                                border.color: "#d1d1d6"
                                border.width: modeSwitch.checked ? 0 : 1

                                Behavior on x {
                                    NumberAnimation {
                                        duration: 200
                                        easing.type: Easing.OutQuad
                                    }
                                }
                            }
                        }

                        contentItem: StyledText {
                            text: modeSwitch.text
                            leftPadding: modeSwitch.indicator.width + 10
                        }
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        borderColor: Theme.empty
                        text: "Unvisited Node"
                        hoverEnabled: false
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        squareColor: Theme.visited
                        text: "Visited Node"
                        hoverEnabled: false
                    }

                    StyledButton {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        useSquare: true
                        squareColor: Theme.path
                        text: "Shortest Path"
                        hoverEnabled: false
                        onClicked: {
                            controller.appMode = Controller.TSP;
                        }
                    }

                    Item {
                        Layout.fillHeight: true
                    }
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
