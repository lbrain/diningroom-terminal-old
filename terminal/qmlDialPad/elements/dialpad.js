function addText(button) {
  if (label.text.length >= 6)
    return;

  label.text += button;
}

function clear() {
  label.text = "";
}

function backspace() {
  if (label.text.length == 0)
    return;
  label.text = label.text.substring(0, label.text.length-1);
}

function enter() {
  if (label.text.length == 0)
    return;
  var idStr = label.text;

}
