import QtQuick 
import QtQuick.Controls
import QtQuick.Layouts

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

        Button {
            id: playingText
            height: parent.height/8
            text: qsTr("Playing")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"

            background: Rectangle {
                color: playingText.clicked ? "#1f1f1f" : "blue"
            }

            onClicked: {
                mainLoader.source = "PlayingScreen.qml"
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

            background: Rectangle {
                color:"#1f1f1f"
            }
            onClicked: mainLoader.source = "LibraryScreen.qml"
        }

        Button {
            id: queueText
            height: parent.height/8
            text: qsTr("Queue")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"

            background: Rectangle {
                color:"#1f1f1f"
            }

            onClicked: {
                mainLoader.source = "QueueScreen.qml"
            }
        }

        Button {
            id: rulesText
            height: parent.height/8
            text: qsTr("Rules")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"

            background: Rectangle {
                color:"#1f1f1f"
            }

            onClicked: {
                mainLoader.source = "RulesScreen.qml"
            }
        }

        Button {
            id: tagsText
            height: parent.height/8
            text: qsTr("Tags")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"

            background: Rectangle {
                color:"#1f1f1f"
            }

            onClicked: {
                mainLoader.source = "TagsScreen.qml"
            }
        }

        Button {
            id: settingsText
            height: parent.height/8
            text: qsTr("Settings")
            font.pointSize: 32
            font.family: "Bahnschrift Light SemiCondensed"
            Layout.alignment: Qt.AlignCenter
            palette.buttonText: "white"

            background: Rectangle {
                color:"#1f1f1f"
            }

            onClicked: {
                mainLoader.source = "SettingsScreen.qml"
            }
        }
    }
}
