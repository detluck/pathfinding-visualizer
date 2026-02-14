pragma ComponentBehavior: Bound
import "../theme"
import QtQuick 2.15

Text{
    id: root

    renderType: Text.NativeRendering
    textFormat: Text.PlainText
    font.family: Theme.font.family.main
    font.pixelSize: Theme.font.size.normal

}
