# Spotify Display

<img width="1050" height="928" alt="image" src="https://github.com/user-attachments/assets/964d4517-3cfc-4f38-9065-95254c6391e3" />
<br />

A cool Spotify display to show me what I’m currently listening to and allow skipping, pausing, playing, and liking! I wanted to design this because I listen to a lot of music, and often have to switch around windows to figure out what song just came on. So, when I saw the starter project on Stasis, I knew it was just what I was looking for!

## File Structure

[hardware/](hardware/) -- STEP files for the physical case parts

- [Case Body.step](<hardware/Case Body.step>) -- The main body of the case; holds the microcontroller, screen, and keyswitches
- [Case Back.step](<hardware/Case Back.step>) -- The back cover of the case; clips on to hide components
- [keys.scad](hardware/keys.scad) -- Parametric file for generating the keycaps; MUST be used with [https://github.com/rsheldiii/Keyv2](https://github.com/rsheldiii/Keyv2)
- [keys.3mf](hardware/keys.3mf) -- Exported mesh of keycaps
- [Full Case Assembly.step](<hardware/Full Case Assembly.step>) -- Full case assembly including modeled electrical components

[software/](software/) -- Arduino ino programs to run the display

- [spotify_display.ino](software/spotify_display/spotify_display.ino) -- The main program with functioning key switches and LED.
- [basic_display.ino](software/basic_display/basic_display.ino) -- Display-only logic (no functioning key switches); connects to WiFi and Spotify API and shows currently playing artist and track on the screen.
- [local_ip.ino](software/local_ip/local_ip.ino) -- Debugging program that connects to WiFi and displays the microcontroller's loal IP address on the screen.

## Wiring Diagram

The KiCAD file for the schematic is available in the [schematic/](schematic/) directory.
<br />

<img width="833" height="1096" alt="image" src="https://github.com/user-attachments/assets/2e8ba4fc-0537-4d67-8148-78ef878cc226" />

## Code - Getting Started

1. Fill in the correct pin numbers at the top of the software files.
2. Create a Spotify API application.
3. Fill in your Spotify client ID and secret and WiFi SSID and password at the top of the software files.
4. Flash the code to the microcontroller.
5. Enjoy!

## Bill of Materials

A CSV version of the bill of materials is avilable at [Spotify Display-bom.csv](<Spotify Display-bom.csv>).
| **Name** | **Purpose** | **Quantity** | **Total Cost (USD)** | **Link** | **Distributor** |
|-------------------------------------------------|-----------------------------------------------------------------------------------------------------------|--------------|----------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------|
| 3mm Red LED | Indicate whether the currently playing song is already on the liked songs playlist | 1 | 0.00 | | Amazon |
| Keycap | Provide icon to label the switch and make pressing comfortable | 4 | 0.00 | | 3D Printed |
| Case Back | Fully encloses the case; keeps everything inside | 1 | 0.00 | | 3D Printed |
| Case Body | Main body of the display; holds all components | 1 | 0.00 | | 3D Printed |
| 26 AWG solid core hookup wire kit | Connecting all of the components together | 1 | 7.79 | https://www.amazon.com/MKBKLLJY-Electrical-Insulation-Assortment-Electronics/dp/B0D97ZJ7W1/ref=sr_1_7?crid=3N1FSAF0ZF9FW&dib=eyJ2IjoiMSJ9.gWNtp8R320XytIQecFuilNPo_bGxgiXRwBO4x5_wrjNNzi3RLb9D_CvXWqrg-yKknv2hABCiKHFZs_VuwTI7fkaT5_KGvq5J0qfa8RVw72Km-IquvhZlwPXlB8YkM_w20_6A1B3IfvCW-jdq6JNMZyulWfHY0HdsSLpUYSMxqHOwFObwQVA-_pDU2eKU_E_xXZVdxt4G2cnu1gv8yeAhBzNprYu1VGAtYDRdFof491U0k_YqusE20T4pFflrjmAF2MvKfwHvmLfoVNsocFqU3DzEO5kwIUZfUKm1VTjFa8Q.dhDNUv5ucKfJYM3yVL0UZZRinxt2QMSK2F2wOXVHSBE&dib_tag=se&keywords=26%2BAWG%2Bsolid%2Bcore%2Bhookup%2Bwire%2Bkit&qid=1778263845&sprefix=26%2Bawg%2Bsolid%2Bcore%2Bhookup%2Bwire%2Bkit%2Caps%2C94&sr=8-7&th=1 | Amazon |
| 10 ct. outemu MX-style tactile blue keyswitches | 4 used for skipping forward, skipping back, and toggling music playback. | 1 | 6.95 | https://www.amazon.com/Switches-Tactile-Dustproof-Mechanical-Keyboard/dp/B0DPLLHBZZ/ref=sr_1_6?crid=EGX5GMWPG45M&dib=eyJ2IjoiMSJ9.pxkIFm2gZSQt9FdXBXIq8LwdfKQmLKb9UIidHbiTNw9BB4pt4zSeCcudXA_1DOnTgAuv5WyDA9YAKe-2YImauYaaOibwQkCcAj_Plq6foHygKLWV3ogDO2E1RLrdSfJd.ud0TU7tZzc4iwKzQr6AgGAGcaIC30_U6BPQNpbD9iao&dib_tag=se&keywords=outemu%2BMX-style%2Btactile%2Bblue%2Bkeyswitches%2B10ct&qid=1778263489&sprefix=outemu%2Bmx-style%2Btactile%2Bblue%2Bkeyswitches%2B10ct%2Caps%2C108&sr=8-6&th=1 | Amazon |
| 1.8"" ST7735 TFT display | Main display; shows current artist and trackname, as well as icons that indicate the keyswitch functions. | 1 | 3.92 | https://www.aliexpress.us/item/3256805209819386.html?spm=a2g0o.cart.0.0.371a38daF3Aanh&mp=1&pdp_npi=6%40dis%21USD%21USD+3.92%21USD+3.92%21%21USD+3.92%21%21%21%402101eee917782630531676829e88b0%2112000032893414817%21ct%21US%217642249123%21%211%210%21&_gl=1*1vs60co*_gcl_aw*R0NMLjE3NzgyMDU0MzIuQ2owS0NRanc4UERQQmhDZUFSSXNBT0p3bVdYUGJEY1duUlEyUWg2akpQOHplYzROSmRNZG9EVFc1aEpTVkFIUWprai1XR1ZwYVlqWkdWWWFBcWNxRUFMd193Y0I.*_gcl_dc*R0NMLjE3NzgyMDU0MzIuQ2owS0NRanc4UERQQmhDZUFSSXNBT0p3bVdYUGJEY1duUlEyUWg2akpQOHplYzROSmRNZG9EVFc1aEpTVkFIUWprai1XR1ZwYVlqWkdWWWFBcWNxRUFMd193Y0I.*_gcl_au*OTk3MjMzMzA0LjE3NzgyMDQ2NDM.*_ga*MTAxNzk0MjIwMTA5NjEyNy4xNzc4MjA0NjQwMzg1*_ga_VED1YSGNC7*czE3NzgyNjI4MDkkbzIkZzEkdDE3NzgyNjM0MTEkajU3JGwwJGgw&gatewayAdapt=glo2usa | AliExpress |
| LOLIN C3 mini ESP32 board | Microcontroller; processes key presses, runs screen, and communicates with Spotify API. | 1 | 0.99 | https://www.aliexpress.us/item/3256804553736450.html?spm=a2g0o.cart.0.0.371a38daF3Aanh&mp=1&pdp_npi=6%40dis%21USD%21USD+5.56%21USD+0.99%21%21USD+0.99%21%21%21%402101eee917782630531676829e88b0%2112000056120453300%21ct%21US%217642249123%21%211%210%21&_gl=1*e3vrrk*_gcl_aw*R0NMLjE3NzgyMDU0MzIuQ2owS0NRanc4UERQQmhDZUFSSXNBT0p3bVdYUGJEY1duUlEyUWg2akpQOHplYzROSmRNZG9EVFc1aEpTVkFIUWprai1XR1ZwYVlqWkdWWWFBcWNxRUFMd193Y0I.*_gcl_dc*R0NMLjE3NzgyMDU0MzIuQ2owS0NRanc4UERQQmhDZUFSSXNBT0p3bVdYUGJEY1duUlEyUWg2akpQOHplYzROSmRNZG9EVFc1aEpTVkFIUWprai1XR1ZwYVlqWkdWWWFBcWNxRUFMd193Y0I.*_gcl_au*OTk3MjMzMzA0LjE3NzgyMDQ2NDM.*_ga*MTAxNzk0MjIwMTA5NjEyNy4xNzc4MjA0NjQwMzg1*_ga_VED1YSGNC7*czE3NzgyNjI4MDkkbzIkZzEkdDE3NzgyNjMyMDIkajYwJGwwJGgw&gatewayAdapt=glo2usa | AliExpress |
