import QtQuick
import QtQuick.Controls

Rectangle {
    width: 1553
    height: 750
    visible: true
    color: "transparent"

    Button {
        id: playingText
        height: parent.height/8
        anchors {
            centerIn: parent
        }
        text: qsTr("Choose directory")
        font.pointSize: 32
        font.family: "Bahnschrift Light SemiCondensed"
    }
}
