import QtQuick
import QtQuick.Controls

Rectangle{
    id: bottomBar
    width: 1553
    height: 300
    anchors {
        right: parent.right
        bottom: parent.bottom
    }
    color: "transparent"

    function formatTime(seconds) {
        var minutes = Math.floor(seconds / 60);
        var remainingSeconds = seconds % 60;
        return minutes + ":" + (remainingSeconds < 10 ? "0" : "") + remainingSeconds;
    }

    property int currentPosition: 0
    property int songLength: 257

    Slider{
        id: trackProgress
        anchors{
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }

        width: 1450
        height: 50
        from: 0
        to: songLength
        stepSize: 1
        value: 0

        onValueChanged: {
            currentTrackProgression.text = formatTime(trackProgress.value);
            currentPosition = trackProgress.value
        }

        Timer {
            interval: 1000 // Update every second
            running: true
            repeat: true

            onTriggered: {
                // Increment the currentPosition by 1 second
                if (currentPosition < songLength & appHandler.playPausing === true) {
                    currentPosition++;
                    trackProgress.value = currentPosition;
                }
            }
        }
    }

    Slider{
        id: volumeBar
        value: appHandler.currentVolume
        y: parent.height - 120
        anchors{
            right: parent.right
            rightMargin: 45
        }
        width: 250
        height: 25

        onPressedChanged:{
            if (!pressed && volumeBar.value === 0){
                appHandler.setMuted(true)
                appHandler.setCurrentVolume(0)
            }
            else if (!pressed && volumeBar.value > 0){
                appHandler.setMuted(false)
                appHandler.setCurrentVolume(volumeBar.value)
            }
        }
    }

    Image {
        id: volumeIcon
        width: 30
        height: 30
        y: parent.height - 120
        source: (appHandler.muted ? "qrc:/mute.png" : "qrc:/volume-down.png")
        fillMode: Image.PreserveAspectFit
        opacity: volumeIconArea.containsMouse ? 1 : 0.5
        anchors{
            right: parent.right
            rightMargin: 320
        }

        MouseArea{
            id: volumeIconArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                // Need to call the backend to change the mute to true or false
                if (appHandler.muted === false){
                    appHandler.setMuted(true)
                    appHandler.setCurrentVolume(0)
                }
                else{
                    appHandler.setMuted(false)
                    appHandler.setCurrentVolume(0)
                }
            }
        }
    }

    Image {
        id: nextSongIcon
        width: 40
        height: 40
        source: "qrc:/forward.png"
        fillMode: Image.PreserveAspectFit
        opacity: nextSongArea.containsMouse ? 1 : 0.5

        anchors{
            bottom: parent.bottom
            right: parent.right
            bottomMargin: 90
            rightMargin: 620

        }

        MouseArea{
            id: nextSongArea
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                //Call the backend and change the text and image of the current, previous and next songs
                // with the queued songs; need signals for now to change the playing pages images and text

                // Resetting the track progress
                currentPosition = 0
                trackProgress.value = 0
                currentTrackProgression.value = formatTime(0)
            }
        }
    }


    Image {
        id: previousSongIcon
        width: 40
        height: 40
        source: "qrc:/previous-track.png"
        fillMode: Image.PreserveAspectFit
        opacity: previousSongArea.containsMouse ? 1 : 0.5

        anchors {
            bottom: parent.bottom
            left: parent.left
            bottomMargin: 90
            leftMargin: 610
        }

        MouseArea{
            id: previousSongArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                //Call the backend and change the text and image of the current, previous and next songs
                // with the queued songs; need signals for now to change the playing pages images and text

                currentPosition = 0
                trackProgress.value = 0
                currentTrackProgression.text = formatTime(0)
            }
        }
    }

    Rectangle {
        id: playButtonBackground
        width: 110
        height: 110
        color: "#ffffff"
        radius: 100
        scale: playButtonMouse.containsMouse ? 1.2 : 1

        anchors{
            bottom: parent.bottom
            left: parent.left
            bottomMargin: 60
            leftMargin: 710
        }

        MouseArea{
            id: playButtonMouse
            anchors.fill: parent
            hoverEnabled: true

            // Really should work we are just calling a method but its not working
            onClicked: appHandler.setPlayPausing(!appHandler.playPausing)
        }

        Image {
            id: playButton
            width: 40
            height: 40
            source: (appHandler.playPausing ? "qrc:/pause.png" :"qrc:/play-button-arrowhead.png")
            anchors.centerIn: parent
            fillMode: Image.PreserveAspectFit
            opacity: 1
            scale: playButtonMouse.containsMouse ? 1.2 : 1
        }
    }

    Text {
        id: currentTrackProgression
        color: "#ffffff"
        text: "0:00"
        font.pixelSize: 25
        textFormat: Text.RichText
        font.family: "Bahnschrift Light SemiCondensed"
        anchors {
            top: parent.top
            left: parent.left
            topMargin: 60
            leftMargin: 50
        }

        // Call method from the backend that gives the current track time
    }

    Text {
        id: currentTrackLength
        color: "#ffffff"
        text: formatTime(songLength)
        font.pixelSize: 25
        textFormat: Text.RichText
        font.family: "Bahnschrift Light SemiCondensed"
        anchors {
            top: parent.top
            right: parent.right
            topMargin: 60
            rightMargin: 50
        }

        // Call method from the backend that gives the current track length
    }
}
