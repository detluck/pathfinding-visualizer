pragma ComponentBehavior: Bound
import "../theme"
import QtQuick

Text{
    id: root

    renderType: Text.NativeRendering
    textFormat: Text.PlainText
    font.pixelSize: 16
    color: Theme.textMain
    fontSizeMode: Text.Fit
    minimumPixelSize: 10
    elide: Text.ElideRight
    verticalAlignment: Text.AlignVCenter

    Behavior on color {
        ColorAnimation { duration: 150 }
    }

}
