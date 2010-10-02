import Qt 4.7

Item {
  id: container

  property string text: "0"
  property int transDuration: 50


  signal clicked

  width: 98; height: 50;
  BorderImage {
    id: normal_image
    source: "images/button_normal.sci"
    anchors.fill: parent
  }

  BorderImage {
    id: hovered_image
    opacity: 0
    source: "images/button_hovered.sci"
    anchors.fill: parent
  }

  BorderImage {
    id: pressed_image
    opacity: 0
    source: "images/button_pressed.sci"
    anchors.fill: parent
  }

  Text {
    id: label
    text: container.text
    color: "white"
    font.pixelSize: parent.width > parent.height ? parent.height * .5 : parent.width * .5
    style: Text.Sunken
    font.bold: true
    styleColor: "black"
    smooth: true
    anchors.centerIn: parent
  }

  MouseArea {
    id: mouseRegion
    anchors.fill: normal_image
    hoverEnabled: true
    onClicked: container.clicked()
  }

  states: [
    State {
      name: "Pressed"
      when: mouseRegion.pressed == true
      PropertyChanges {
        target: pressed_image
        opacity: 1
      }
      PropertyChanges {
        target: label
        anchors.verticalCenterOffset: 1
      }

    },

    State {
      name: "Hovered"
      when: mouseRegion.containsMouse == true && !mouseRegion.pressed
      PropertyChanges {
        target: hovered_image
        opacity: 1
      }
    }
  ]

  transitions: [
    Transition {
      from: "Hovered"
      to: "Pressed"
      reversible: true
      PropertyAnimation {
        property: "opacity"
        duration: transDuration
      }
    },

    Transition {
      from: ""
      to: "Hovered"
      reversible: true
      PropertyAnimation {
        property: "opacity"
        duration: transDuration*5
      }
    },

    Transition {
      from: ""
      to: "Pressed"
      reversible: true
      PropertyAnimation {
        property: "opacity"
        duration: transDuration
      }
    }
  ]

}
