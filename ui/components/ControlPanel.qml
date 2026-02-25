pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: root
    width: 420
    height: 260
    color: "white"

    ColumnLayout{
        anchors.fill: parent
        spacing: 20

        Rectangle{
            id: row1Back
            Layout.fillHeight: true
            Layout.fillWidth: true
            RowLayout{
                spacing: 20
                StyledText{
                    Layout.fillHeight: true
                    width: root.width / 4
                    id: titel
                    text: "Pathfinding-Visualizer"   
                }
                AlgoSelector{
                    Layout.fillHeight: true
                    id: selector
                    Layout.fillWidth: true
                }
            }
        }

        RowLayout{
            spacing: 20
            ColumnLayout{
                id: controlButtons
                spacing: 5
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Start"
                    svgPath: "../assets/svgs/start.svg"
                }
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Terminate"
                    svgPath: "../assets/svgs/terminate.svg"
                }
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Pause"
                    svgPath: "../assets/svgs/pause.svg"
                }
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Clear Grid"
                    svgPath: "../assets/svgs/clean.svg"
                }
            }
            ColumnLayout{
                id: editButtons
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Start node"
                    svgPath: "../assets/svgs/startNode.svg"
                }
                StyledButton{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Target node"
                    svgPath: "../assets/svgs/endNode.svg"
                }
                StyledButton{
                    useSquare: true
                    squareColor: "black"
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Wall"
                }
            }
            ColumnLayout{
                id: explanaitionLabels
                spacing: 20
                StyledRect{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Visited Node"
                    squareColor: "blue"
                }
                StyledRect{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Unvisited Node"
                    squareColor: "green"
                }
                StyledRect{
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    text: "Shortest Path"
                    squareColor: "yellow"
                }

            }
        }
    }
}
