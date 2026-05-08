# Spotify Display
<img width="1225" height="1029" alt="1778187869112-5wrynm" src="https://github.com/user-attachments/assets/4e6d184c-b206-4ffe-96e4-1a0693f02caa" />
<br />
A cool Spotify display to show me what I’m currently listening to and allow skipping, pausing, and playing!

## Bill of Materials
- 1x LOLIN C3 mini ESP32 board
- 1x 1.8" ST7735 TFT display
- 3x outemu MX-style tactile blue keyswitches
- 1x 3D printed case body
- 1x 3D printed case back

## File Structure
[hardware/](hardware/) -- STEP files for the physical case parts
- [Case Body.step](<hardware/Case Body.step>) -- The main body of the case; holds the microcontroller, screen, and keyswitches
- [Case Back.step](<hardware/Case Back.step>) -- The back cover of the case; clips on to hide components
- [Full Case Assembly.step](<hardware/Full Case Assembly.step>) -- Full case assembly including modeled electrical components

[software/](software/) -- Arduino ino programs to run the display
- [spotify_display.ino](software/spotify_display/spotify_display.ino) -- The main program with functioning key switches.
- [basic_display.ino](software/basic_display/basic_display.ino) -- Display-only logic (no functioning key switches); connects to WiFi and Spotify API and shows currently playing artist and track on the screen.
- [local_ip.ino](software/local_ip/local_ip.ino) -- Debugging program that connects to WiFi and displays the microcontroller's loal IP address on the screen.

## Code - Getting Started
1. Fill in the correct pin numbers at the top of the software files.
2. Create a Spotify API application.
3. Fill in your Spotify client ID and secret and WiFi SSID and password at the top of the software files.
4. Flash the code to the microcontroller.
5. Enjoy!
