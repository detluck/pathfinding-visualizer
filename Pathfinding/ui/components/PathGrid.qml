import QtQuick
import QtQuick.Layouts
import Pathfinding

Rectangle{
    id: root
    onWidthChanged: updateGridSize()
    onHeightChanged: updateGridSize()

    color: Theme.bgGrid

    Behavior on color { ColorAnimation { duration: 150 } }

    function updateGridSize() {
        if (grid.cellWidth === 0 || grid.cellHeight === 0) return;

        var newCols = Math.floor(width / grid.cellWidth)
        var newRows = Math.floor(height / grid.cellHeight)

        gridModel.resizeModel(newCols, newRows)
    }

    Component.onCompleted: updateGridSize()

    GridView{
        id: grid
        interactive: false
        model: gridModel
        anchors.centerIn: parent
        width: gridModel.width * cellWidth
        height: gridModel.height * cellHeight
        cellHeight: 20
        cellWidth: 20
        property int hoverIndex: -1
        delegate: GridTile{
            id: tile
            width: 20
            height: 20
            isHovered: index === grid.hoverIndex
            color:{
                switch(type){
                    case 0: return Theme.bgGrid;
                    case 1: return Theme.visited;
                    case 2: return Theme.wall;
                    case 3: return Theme.path;
                    case 6: switch(true){
                                case weight <= 33:
                                    return Theme.weightLight
                                case weight <= 66:
                                    return Theme.weightMiddle
                                case weight <= 100:
                                    return Theme.weightHeavy
                                default:
                                    return Theme.bgBaseReverse
                            }
                    default: return Theme.bgGrid;
                }
            }
            opacity: type === 6? Math.max(0.2, weight / 100.0): 100.0
            svgPath: getRightSVG(type)
            function getRightSVG(type){
                switch(type){
                        case 4: return "../assets/svgs/startNode.svg"
                        case 5: return "../assets/svgs/endNode.svg"
                        default: return ""
                }
            }
        }
    }
    MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                preventStealing: true

                function tileIndexAt(x, y) {
                    var col = Math.floor(x / grid.cellWidth)
                    var row = Math.floor(y / grid.cellHeight)

                    var colsInModel = gridModel.width

                    if (col < 0 || col >= colsInModel || row < 0 || row >= gridModel.height)
                        return -1

                    var idx = row * colsInModel + col

                    if (idx >= 0 && idx < gridModel.rowCount())
                        return idx

                    return -1
                }

                function paintTile(x, y) {
                    var idx = tileIndexAt(x, y)
                    if (idx >= 0) controller.handleClick(idx)
                }

                onPressed: paintTile(mouseX, mouseY)
                onPositionChanged: {
                    grid.hoverIndex = tileIndexAt(mouseX, mouseY)
                    if (pressedButtons & Qt.LeftButton) paintTile(mouseX, mouseY)
                }
                onExited: grid.hoverIndex = -1
    }
}
