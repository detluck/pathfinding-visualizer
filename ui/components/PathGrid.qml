pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Layouts

Rectangle{
    id: root
    property int tileNumber

    GridView{
        model: ok //cpp model
        delegate: GridTile{

        }
    }
}
