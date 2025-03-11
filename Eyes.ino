#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <FluxGarage_RoboEyes.h>
roboEyes Eyes; 


void setup() {
  Serial.begin(9600);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C or 0x3D
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Startup robo eyes
  Eyes.begin(SCREEN_WIDTH, SCREEN_HEIGHT, 100); // screen-width, screen-height, max framerate

  // Define some automated eyes behaviour
  Eyes.setAutoblinker(ON, 2, 1); // Eyes blink - ON/OFF, Seconds in between blinks, variation betweeen blinks in seconds
  // roboEyes.setIdleMode(ON, 2, 2); // Eyes look in random direction
  
  // Define eye shapes, all values in pixels
  Eyes.setWidth(33, 33); // left eye, right eye
  Eyes.setHeight(36, 36); // left eye, right eye
  Eyes.setBorderradius(8, 8); // left eye, right eye
  Eyes.setSpacebetween(10); // space between the eyes

  // Define mood, curiosity and position
  Eyes.setMood(ANGRY); // Can be TIRED, ANGRY, HAPPY, DEFAULT
  Eyes.setPosition(DEFAULT); // Can be N, NE, E, SE, S, SW, W, NW, DEFAULT (default = horizontally and vertically centered)
  // Eyes.setCuriosity(ON); // When turned on, height of the outer eyes increases when moving to the very left or very right

  // Set horizontal or vertical flickering
  // roboEyes.setHFlicker(ON, 2); // horizontal flicker: alternately displacing the eyes in the defined amplitude in pixels
  // roboEyes.setVFlicker(ON, 2); // vertical flicker: alternately displacing the eyes in the defined amplitude in pixels

  // Play prebuilt oneshot animations
  // Eyes.anim_confused(); // confused - eyes shaking left and right
  Eyes.anim_laugh(); // laughing - eyes shaking up and down
  
} // end of setup


void loop() {
 Eyes.update(); // update eyes drawings
}
