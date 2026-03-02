pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import App.Controller 1.0

Rectangle{
    id: root
    width: 420
    height: 260
    color: "white"

    GridLayout{
        anchors.fill: parent
        anchors.margins: 10
        columns: 3
        columnSpacing: 250

        StyledText{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.columnSpan: 2
            id: titel
            text: "Pathfinding-Visualizer"
        }
        AlgoSelector{
            id: selector
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Start"
            svgPath: "../assets/svgs/start.svg"
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Start node"
            tipText: "Click to set the start node on the grid"
            svgPath: "../assets/svgs/startNode.svg"

            onClicked:{
                if(svgPath !== ""){
                cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
                controller.setClickType(Controller.StartNode)
                }
            }
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            useSquare: true
            borderColor: "skyblue"
            text: "Unvisited Node"
            hoverEnabled: false
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Terminate"
            svgPath: "../assets/svgs/terminate.svg"

            onClicked: {
                controller.setClickType(Controller.Stop)
            }
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Target node"
            tipText: "Click to set the target node on the grid"
            svgPath: "../assets/svgs/endNode.svg"

            onClicked:{
                controller.setClickType(Controller.TargetNode)
                if(svgPath !== ""){
                cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
                }
            }
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            useSquare: true
            squareColor: "blue"
            text: "Visited Node"
            hoverEnabled: false
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Pause"
            svgPath: "../assets/svgs/pause.svg"

            onClicked:{
                controller.setClickType(Controller.Pause)
            }
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            svgPath: "../assets/svgs/wall.svg"
            text: "Wall"
            tipText: "Click and hold mouse button to draw walls"

            onClicked:{
                controller.setClickType(Controller.Wall)
                if(svgPath !== ""){
                cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
                }
            }
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            useSquare: true
            squareColor: "yellow"
            text: "Shortest Path"
            hoverEnabled: false
        }
        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Clear Grid"
            svgPath: "../assets/svgs/clean.svg"
            tipText: "clears the entire grid"

            onClicked: {
                controller.setClickType(Controller.Clear)
            }
        }

        StyledButton{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            text: "Deleate Item"
            svgPath: "../assets/svgs/deleate.svg"
            tipText: "Click and choose the item to deleate"

            onClicked:{
                controller.setClickType(Controller.Deleate)
                if(svgPath !== ""){
                cursorHelper.setCursor("Pathfinding/ui" + svgPath.substring(2))
                }
            }
        }
    }
}
