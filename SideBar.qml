import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Rectangle{
    id: leftSideBar
    width: 367
    height: 1080
    anchors {
        left: parent.left
    }
    color: "#1f1f1f"

    Image {
        id: mediaLogo
        width: 55
        height: 55
        source: "qrc:/640px-Windows_Media_Player_simplified_logo.svg.png"
    }

    ColumnLayout{
        id: buttonColumn
        y: 200
        height: leftSideBar.height/2
        width: leftSideBar.width
        spacing: 75
        Material.theme: Material.Dark

        Button {
            id: playingText
            height: parent.height/8
            text: qsTr("Playing")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            Material.background: appHandler.currentPage === "playing" ?  "#2B8FEB" : "#1F1F1F"

            onClicked: {
                mainLoader.source = "PlayingScreen.qml"
                appHandler.setCurrentPage("playing")
            }
        }

        Button {
            id: libraryText
            height: parent.height/8
            text: qsTr("Library")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"
            Material.background: appHandler.currentPage === "library" ?  "#2B8FEB" : "#1F1F1F"
            onClicked: {
                mainLoader.source = "LibraryScreen.qml"
                appHandler.setCurrentPage("library")
            }
        }

        Button {
            id: queueText
            height: parent.height/8
            text: qsTr("Queue")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            Material.background: appHandler.currentPage === "queue" ?  "#2B8FEB" : "#1F1F1F"

            onClicked: {
                mainLoader.source = "QueueScreen.qml"
                appHandler.setCurrentPage("queue")
            }
        }

        Button {
            id: rulesText
            height: parent.height/8
            text: qsTr("Rules")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            Material.background: appHandler.currentPage === "rules" ?  "#2B8FEB" : "#1F1F1F"

            onClicked: {
                mainLoader.source = "RulesScreen.qml"
                appHandler.setCurrentPage("rules")
            }
        }

        Button {
            id: tagsText
            height: parent.height/8
            text: qsTr("Tags")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            Material.background: appHandler.currentPage === "tags" ?  "#2B8FEB" : "#1F1F1F"

            onClicked: {
                mainLoader.source = "TagsScreen.qml"
                appHandler.setCurrentPage("tags")
            }
        }

        Button {
            id: settingsText
            height: parent.height/8
            text: qsTr("Settings")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            Material.background: appHandler.currentPage === "settings" ?  "#2B8FEB" : "#1F1F1F"

            onClicked: {
                mainLoader.source = "SettingsScreen.qml"
                appHandler.setCurrentPage("settings")
            }
        }
    }
}
