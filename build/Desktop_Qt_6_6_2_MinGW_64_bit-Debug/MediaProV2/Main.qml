import QtQuick
import QtQuick.Controls

Window {
    id: root
    width: 1920
    height: 1080
    visible: true
    title: "MediaPro"
    color: "#000000"

    SideBar{
        id: sideBar
    }

    BottomBar1 {
        id: mainBottomBar
    }

    Loader {
        id: mainLoader
        source: "QueueScreen.qml"
    }
}
