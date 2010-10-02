import Qt 4.7

Rectangle {
    width: 20
    height: 20

    radius: 4
    border.width: 1
    border.color: "gray"

    property string text: ""

    Text {
      id: label
      color: "black"
      font.pixelSize: parent.width > parent.height ? parent.height * .9 : parent.width * .9
      text: parent.text
      font.bold: true
      smooth: true
      anchors.centerIn: parent
    }

}
