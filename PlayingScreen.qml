import QtQuick
import QtQuick.Controls

// When we load this screen, we read the currently, previous, and next playing data from the backend
// instead of using information pre-populated

Rectangle {
    width: 1553
    height: 750
    visible: true
    color: "transparent"

    Rectangle{
        id: currentlyPlayingAlbumBorder
        x: 972
        y: 52
        width: 315
        height: 363
        color: "transparent"
        border.color: "white"
        border.width: 2

        Image {
            id: currentlyPlayingAlbum
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/_AM__(Arctic_Monkeys).jpg"
        }
    }

    Rectangle {
        id: previousPlayingAlbumBorder
        x: 485
        y: 206
        width: 315
        height: 363
        color: "transparent"
        border.color: "white"
        border.width:2
        opacity: previousAlbumArea.containsMouse ? 1 : 0.5

        Image {
            id: previousPlayingAlbum
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/_AM__(Arctic_Monkeys).jpg"
            opacity: previousAlbumArea.containsMouse ? 1 : 0.5

            MouseArea{
                id: previousAlbumArea
                anchors.fill: parent
                hoverEnabled: true

                // Need logic for handling when a previous track is clicked - grab metadata from the song
                onClicked: {
                    // Setting the items
                    previousPlayingAlbum.source = ""
                    previousPlayingArtist.text = ""
                    previousPlayingTitle.text = ""

                    currentlyPlayingAlbum.source = ""
                    currentPlayingTitle.text = ""
                    currentPlayingArtist.text = ""

                    nextPlayingAlbum.source = ""
                    nextPlayingTitle.text = ""
                    nextPlayingArtist.text = ""

                    // Resetting the track progress
                    trackProgress.value = ""
                }
            }
        }
    }

    Rectangle{
        id: nextPlayingAlbumBorder
        x: 1428
        y: 206
        width: 315
        height: 363
        color: "transparent"
        border.color: "white"
        border.width:2
        opacity: nextAlbumArea.containsMouse ? 1 : 0.5

        Image {
            id: nextPlayingAlbum
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/_AM__(Arctic_Monkeys).jpg"
            opacity: nextAlbumArea.containsMouse ? 1 : 0.5

            MouseArea{
                id: nextAlbumArea
                anchors.fill: parent
                hoverEnabled: true

                // Need logic for handling when a next track is clicked - grab metadat from the song
                onClicked: {
                    // Setting the items
                    previousPlayingAlbum.source = ""
                    previousPlayingArtist.text = ""
                    previousPlayingTitle.text = ""

                    currentlyPlayingAlbum.source = ""
                    currentPlayingTitle.text = ""
                    currentPlayingArtist.text = ""

                    nextPlayingAlbum.source = ""
                    nextPlayingTitle.text = ""
                    nextPlayingArtist.text = ""

                    // Resetting the track progress
                    trackProgress.value = ""
                }
            }
        }
    }

    Text {
        id: previousPlayingTitle
        x: 485
        y: 593
        opacity: previousAlbumArea.containsMouse ? 1 : 0.5
        color: "#ffffff"
        text: "Snap Out of It"
        font.pixelSize: 60
        textFormat: Text.RichText
        font.family: "Bahnschrift SemiBold"
    }

    Text {
        id: previousPlayingArtist
        x: 485
        y: 715
        opacity: previousAlbumArea.containsMouse ? 1 : 0.5
        color: "#ffffff"
        text: "Arctic Monkeys"
        font.pixelSize: 30
        textFormat: Text.RichText
        font.family: "Bahnschrift Light SemiCondensed"
    }

    Text {
        id: currentPlayingTitle
        x: 972
        y: 450
        color: "#ffffff"
        text: "Knee Socks"
        font.pixelSize: 60
        textFormat: Text.RichText
        font.family: "Bahnschrift SemiBold"
    }

    Text {
        id: currentPlayingArtist
        x: 972
        y: 540
        opacity: 1
        color: "#ffffff"
        text: "Arctic Monkeys"
        font.pixelSize: 30
        textFormat: Text.RichText
        font.family: "Bahnschrift Light SemiCondensed"
    }

    Text {
        id: nextPlayingTitle
        x: 1428
        y: 593
        opacity: nextAlbumArea.containsMouse ? 1 : 0.5
        color: "#ffffff"
        text: "I Wanna Be Yours"
        font.pixelSize: 60
        textFormat: Text.RichText
        font.family: "Bahnschrift SemiBold"
    }

    Text {
        id: nextPlayingArtist
        x: 1428
        y: 715
        opacity: nextAlbumArea.containsMouse ? 1 : 0.5
        color: "#ffffff"
        text: "Arctic Monkeys"
        font.pixelSize: 30
        textFormat: Text.RichText
        font.family: "Bahnschrift Light SemiCondensed"
    }
}
