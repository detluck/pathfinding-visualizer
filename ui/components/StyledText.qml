pragma ComponentBehavior: Bound
import "../theme"
import QtQuick

Text{
    id: root

    renderType: Text.NativeRendering
    textFormat: Text.PlainText
    font.family: Theme.font.family.main
    font.pixelSize: Theme.font.size.normal
    fontSizeMode: Text.Fit
    minimumPixelSize: 10
    elide: Text.ElideRight
    verticalAlignment: Text.AlignVCenter

}
