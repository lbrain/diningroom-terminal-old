import Qt 4.7
import "elements"
import "elements/dialpad.js" as Logic

Rectangle {
  id: window

  signal login

  width: 700; height: 700; color: "gray"

  Rectangle {
    color: "#333333"
    width: column.width; height: column.height
    border.color: "#aaaaaa"; border.width: 3
    smooth: true
    radius: 10
    anchors.rightMargin: -8; anchors.leftMargin: -8;
    anchors.bottomMargin: -8; anchors.topMargin: -8;
    anchors.left: column.left; anchors.right: column.right
    anchors.top: column.top; anchors.bottom: column.bottom
  }

  Column {
    id: column
    spacing: 2
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter

    Row {
      id: row0
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter

      TextField { id: label; height: 50; width: column.width }
    }

    Row {
      id: row1
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter
      Button { id: button1; text: "1"; width: 80; height: 80; onClicked: Logic.addText("1") }
      Button { id: button2; text: "2"; width: 80; height: 80; onClicked: Logic.addText("2") }
      Button { id: button3; text: "3"; width: 80; height: 80; onClicked: Logic.addText("3") }
    }

    Row {
      id: row2
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter
      Button { id: button4; text: "4"; width: 80; height: 80; onClicked: Logic.addText("4") }
      Button { id: button5; text: "5"; width: 80; height: 80; onClicked: Logic.addText("5") }
      Button { id: button6; text: "6"; width: 80; height: 80; onClicked: Logic.addText("6") }
    }

    Row {
      id: row3
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter
      Button { id: button7; text: "7"; width: 80; height: 80; onClicked: Logic.addText("7") }
      Button { id: button8; text: "8"; width: 80; height: 80; onClicked: Logic.addText("8") }
      Button { id: button9; text: "9"; width: 80; height: 80; onClicked: Logic.addText("9") }
    }

    Row {
      id: row4
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter
      Button { id: buttonBackspace; text: "<"; width: 80; height: 80; onClicked: Logic.backspace(); }
      Button { id: button0;         text: "0"; width: 80; height: 80; onClicked: Logic.addText("0") }
      Button { id: buttonClear;     text: "C"; width: 80; height: 80; onClicked: Logic.clear() }
    }

    Row {
      id: row5
      spacing: 2
      anchors.horizontalCenter: parent.horizontalCenter
      Button { id: buttonEnter; text: "Вход"; width: column.width; height: 50; onClicked: login() }
    }
  }
}
