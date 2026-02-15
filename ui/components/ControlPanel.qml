pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: root

    RowLayout{
        spacing: 20
        Rectangle{
            id: row1Back
            StyledText{
                Layout.fillWidth: true
                id: titel
                text: "Pathfinding-Visualizer"   
            }
            AlgoSelector{
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
                iconSize: 40
                fontSize: 40
                svgPath: "../assets/svgs/start.svg"
            }
            StyledButton{
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "Terminate"
                iconSize: 40
                fontSize: 40
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
            
        }
    }
}
