import QtQuick
import QtQuick.Layouts

Rectangle{
    id: root

    GridView{
        id: grid
        interactive: false
        model: gridModel
        anchors.fill: parent
        cellWidth: 20
        cellHeight: 20
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

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            preventStealing: true

            function tileIndexAt(x, y) {
                var col = Math.floor(x / grid.cellWidth)
                var row = Math.floor((y + grid.contentY) / grid.cellHeight)
                var idx = row * Math.floor(grid.width / grid.cellWidth) + col
                if (idx >= 0 && idx < gridModel.rowCount()) return idx
                    return -1
                }
                function paintTile(x, y) {
                    var idx = tileIndexAt(x, y)
                    if (idx < 0) return

                    controller.handleClick(idx)


                    // if (cursorHelper.cursor !== "") {
                    //     var item = grid.itemAtIndex(idx)
                    //     if (item) {
                    //         item.svgPath = "qrc:/" + cursorHelper.cursor
                    //     }
                    // }
                }

                onPressed: {
                    paintTile(mouseX, mouseY)
                }

                onPositionChanged: {
                    grid.hoverIndex = tileIndexAt(mouseX, mouseY)
                    if (pressedButtons & Qt.LeftButton) {
                        paintTile(mouseX, mouseY)
                    }
                }

                onExited: {
                    grid.hoverIndex = -1
                }
        }
    }
}
