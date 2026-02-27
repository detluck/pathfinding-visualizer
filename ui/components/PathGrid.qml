import QtQuick
import QtQuick.Layouts

Rectangle{
    id: root

    border.color: "black"

    GridView{
        model: gridModel
        anchors.fill: parent
        cellWidth: 20
        cellHeight: 20
        delegate: GridTile{
            width: 20
            height: 20
            color:{
                switch(type){
                    case 0: return "white";
                    case 1: return "blue";
                    case 2: return "black";
                    case 3: return "yellow";
                    default: return "white";
                }
            }
        }
    }
}
