import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    width: 1553
    height: 750
    visible: true
    color: "transparent"

    property string searchString: ""

    // Creating the search bar at the top of the screen
    Rectangle{
        id: searchBar
        color: "#1F1F1F"
        radius: 20
        width: parent.width - 75
        height: 75

        anchors {
            top: parent.top
            left: parent.left
            leftMargin: 400
            topMargin: 25
        }

        TextField {
            id: searchInput
            width: parent.width - 150
            height: 35
            placeholderText: "Search tags, songs, artists, length"
            anchors.centerIn: parent
            font.pixelSize: 20
            anchors.right: parent.right
            anchors.rightMargin: 50

            onEditingFinished: {
                searchString = searchInput.text
            }
        }

        Image{
            id: searchIcon
            height: 20
            width: 20
            source: "qrc:/magnifying-glass.png"
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 40
        }

        // Creating the rectangle with the names
        Rectangle{
            id: nameRectangle
            width: parent.width
            height: 65
            color: "#1F1F1F"
            border.color: "white"
            anchors{
                top: parent.top
                topMargin: 100
            }

            Text{
                id: tagsTitle
                text: "Tags"
                font.family: "Bahnschrift SemiBold"
                font.pixelSize: 30
                color: "white"
                anchors{
                    top: parent.top
                    left: parent.left
                    leftMargin: 35
                    topMargin: 15
                }
            }

            Text{
                id: songsTitle
                text: "Songs"
                font.family: "Bahnschrift SemiBold"
                font.pixelSize: 30
                color: "white"
                anchors{
                    top: parent.top
                    left: parent.left
                    topMargin: 15
                    leftMargin: 450

                }
            }

            Text{
                id: artistTitle
                text: "Artist"
                font.family: "Bahnschrift SemiBold"
                font.pixelSize: 30
                color: "white"
                anchors{
                    top: parent.top
                    right: parent.right
                    topMargin: 15
                    rightMargin: 450
                }
            }

            Text{
                id: lengthTitle
                text: "Length"
                font.family: "Bahnschrift SemiBold"
                font.pixelSize: 30
                color: "white"
                anchors{
                    top: parent.top
                    right: parent.right
                    topMargin: 15
                    rightMargin: 35
                }
            }
        }
    }

    // List view item
    ListView{

        width: parent.width - 75
        height: parent.height
        model: ListModel {
            ListElement { name: "Item1"}
            ListElement {name: "item2"}
        }

        delegate: Item {
            width: parent.width
            height: 40
            Text{
                anchors.centerIn: parent
                text: model.name
            }
        }
    }
}
