import processing.serial.*;

Serial myPort;
int xPos = 0;
int yPos = 0;

void setup() {
  size(400, 300);
  myPort = new Serial(this, "COM3", 9600);
  myPort.bufferUntil('\n');
  background(255);
}

void draw() {
}

void serialEvent(Serial myPort) {
  String distanceString = myPort.readStringUntil('\n');
  if (distanceString != null) {
    distanceString = distanceString.trim();
    int distance = Integer.parseInt(distanceString);
    stroke(0);
    line(xPos, height, xPos, height - distance);
    xPos++;
    if (xPos >= width) {
      xPos = 0;
      background(255);
    }
  }
}
