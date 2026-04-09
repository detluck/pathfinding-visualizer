import QtQuick
import QtQuick.Layouts

Rectangle{
    id: root

    onWidthChanged: updateGridSize()
    onHeightChanged: updateGridSize()

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
                    case 0: return "white";
                    case 1: return "blue";
                    case 2: return "black";
                    case 3: return "yellow";
                    default: return "white";
                }
            }
            svgPath: getRightSVG(type)
            function getRightSVG(type){
                switch(type){
                        case 4: return "../assets/svgs/startNode.svg"
                        case 5: return "../assets/svgs/endNode.svg"
                        default: return ""
                }
            }
        }

        // MouseArea {
        //     anchors.fill: parent
        //     hoverEnabled: true
        //     preventStealing: true

        //     function tileIndexAt(x, y) {
        //         var col = Math.floor(x / grid.cellWidth)
        //         var row = Math.floor((y + grid.contentY) / grid.cellHeight)
        //         var idx = row * Math.floor(grid.width / grid.cellWidth) + col
        //         if (idx >= 0 && idx < gridModel.rowCount()) return idx
        //             return -1
        //         }
        //         function paintTile(x, y) {
        //             var idx = tileIndexAt(x, y)
        //             if (idx < 0) return

        //             controller.handleClick(idx)


        //             // if (cursorHelper.cursor !== "") {
        //             //     var item = grid.itemAtIndex(idx)
        //             //     if (item) {
        //             //         item.svgPath = "qrc:/" + cursorHelper.cursor
        //             //     }
        //             // }
        //         }

        //         onPressed: {
        //             paintTile(mouseX, mouseY)
        //         }

        //         onPositionChanged: {
        //             grid.hoverIndex = tileIndexAt(mouseX, mouseY)
        //             if (pressedButtons & Qt.LeftButton) {
        //                 paintTile(mouseX, mouseY)
        //             }
        //         }

        //         onExited: {
        //             grid.hoverIndex = -1
        //         }
        // }
    }
    MouseArea {
                anchors.fill: parent // Füllt jetzt nur noch die tatsächliche Grid-Fläche!
                hoverEnabled: true
                preventStealing: true

                function tileIndexAt(x, y) {
                    // Da die MouseArea nur so groß wie das Grid ist,
                    // sind x und y jetzt perfekt lokal zum ersten Tile oben links.
                    var col = Math.floor(x / grid.cellWidth)
                    var row = Math.floor(y / grid.cellHeight)

                    // Nutze IMMER die Breite aus dem Model für den Index
                    var colsInModel = gridModel.width

                    // Sicherheit Check
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
